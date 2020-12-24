#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* f1 = fopen("file1.txt", "r");
    FILE* f2 = fopen("file2.txt","w");
    if(f1 == NULL || f2==NULL)
    {
        return 1;
    }
    char *stroka = malloc(100*sizeof(char));
    fgets(stroka, 99, f1);
    fprintf(f2,"stroka iz faila:\n%s", stroka);

    char* s1 = strstr(stroka,"  ");
    char* s2 = strstr(stroka,".  ");
    char* s3 = strstr(stroka," .");
    while(s1 != NULL || s2 != NULL || s3 != NULL)
    {
        if(s1 != NULL)
        {
            char ssssss[100];
            strcpy(ssssss,s1);
            strcpy(s1,ssssss+1);
            s1 = strstr(stroka,"  ");
            s2 = strstr(stroka,".  ");
            s3 = strstr(stroka," .");
        }
        if(s2 != NULL)
        {
            char ssssss[100];
            strcpy(ssssss,s2);
            strcpy(s2+1,ssssss+2);
            s1 = strstr(stroka,"  ");
            s2 = strstr(stroka,".  ");
            s3 = strstr(stroka," .");
        }
        if(s3 != NULL)
        {
            char ssssss[100];
            strcpy(ssssss,s3);
            strcpy(s3,ssssss+1);
            s1 = strstr(stroka,"  ");
            s2 = strstr(stroka,".  ");
            s3 = strstr(stroka," .");
        }
    }
    if(stroka[0]==' ')
    {
        char ssssss[100];
        strcpy(ssssss,stroka);
        strcpy(stroka,ssssss+1);
    }
    int sjfvbdfvb = strlen(stroka);
    if(stroka[sjfvbdfvb-1]==' ')
    {
        stroka[sjfvbdfvb-1]='\0';
    }
    fprintf(f2,"\nstroka bez probelov:\n%s", stroka);



    char s = stroka[strlen(stroka)- 1];
    int r1 = strlen(stroka) - 1;
    while (s == '.')
    {
        r1-=1;
        s = stroka[r1];
    }
    int l1 = r1;
    while (s != ' ')
    {
        l1-=1;
        s = stroka[l1];
    }
    l1+=1;
    int j = r1 - l1 + 1;
    char slovo[256];
    for (int i = l1; i <= r1; i++)
    {
        slovo[i - l1] = stroka[i];
    }
    slovo[j] = '\0';
    printf("\nslovo:%s\n", slovo);

    char* strokaaaa = malloc(100*sizeof(char));
    strokaaaa[0]='\0';
    char* s4 = strtok(stroka,". ");
    while(s4!=NULL)
    {
        if(strcmp(s4,slovo)!=0)
        {
            strcat(strokaaaa, s4);
            strcat(strokaaaa, " ");
        }
        s4=strtok(NULL,". ");
    }
    fprintf(f2,"\nstroka bez poslednego slova:\n%s\n",strokaaaa);


    char* strokaaaa2 = malloc(100*sizeof(char));
    strokaaaa2[0]='\0';
    char* s5 = strtok(strokaaaa,". ");
    while(s5!=NULL)
    {
        char hhh[100];
        char rrr[2];
        strcpy(hhh,s5);
        int aaaa = strlen(hhh);
        rrr[0]=hhh[aaaa-1];
        rrr[1]='\0';
        for(int i = 0; i < aaaa; ++i)
        {
            char rrr1[2];
            rrr1[0]=hhh[i];
            rrr1[1]='\0';
            if(hhh[i]!=rrr[0] || i == aaaa-1)
            {
                strcat(strokaaaa2, rrr1);
            }
        }
        strcat(strokaaaa2," ");
        s5=strtok(NULL,". ");
    }
    fprintf(f2,"individualnoe zadanie:\n%s\n",strokaaaa2);
    return 0;
}
