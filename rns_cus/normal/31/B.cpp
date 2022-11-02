#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char *take, *ss[500],txt[500];
    gets(txt);int y=0;
for(i=0;i<strlen(txt)-1;i++)
    if((txt[i]=='@')&&(txt[i+1]=='@')) {y=1;break;}
if(y==1) printf("No solution\n");
else if(txt[0] == '@') printf("No solution\n");
else if(txt[strlen(txt) - 1] == '@') printf("No solution\n");
else{
    int k = 0;
    for(take = strtok(txt, "@"); take != NULL; take = strtok(NULL,"@"),k ++)
        ss[k] = take;
    int len, flag=0;
  if(k == 1)   printf("No solution\n");
  else{
    for(int i=1; i < k-1; i ++)
        if(strlen(ss[i]) < 2) {
                printf("No solution\n");
                flag = 1;
                break;
        }
    if(flag==0) {
        for(i = 0; i < k; i ++){
            if(i == 0) printf("%s@", ss[i]);
            else if(i == k-1) printf("%s\n", ss[i]);
            else {
                printf("%c,",ss[i][0]);
                for(int j = 1; j < strlen(ss[i]); j ++)
                    printf("%c",ss[i][j]);
                printf("@");
            }
        }
    }
}
}
}