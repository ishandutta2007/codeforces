#include<stdio.h>
#include<cstring>
#define MAXN 1100
char str[MAXN];int n,p;
char ans[MAXN];
bool checker(int ed)
{
     for(int i=1;i<=ed;i++)ans[i]=str[i];
     for(int i=ed+1;i<=n;i++)
     {
             bool f=0;
             for(int j=1;j<=p;j++)
             {
                     if(i==ed+1&&j<=str[i])continue;
                     if(i>1)
                     if(j==ans[i-1])continue;
                     if(i>2)
                     if(j==ans[i-2])continue;
                     f=1;ans[i]=j;break;
                     }
             if(!f)return 0;
             }
     return 1;
}
void Output()
{
     for(int i=1;i<=n;i++)printf("%c",ans[i]+'a'-1);
}                 
void TP()
{
     if(p==1){printf("NO");return;}
     if(n>2){printf("NO");return;}
     if(n==2)
     {
             if(str[1]>str[2])
             {
                              printf("NO");
                              return;
                              }
             printf("ba");
             }
     else
     if(n==1)
     {
             if(str[1]==p)printf("NO");
             else printf("b");
             }
}
int main()
{
    scanf("%d%d",&n,&p);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)str[i]-='a'-1;
    if(p<=2)
    {
            TP();
            return 0;
           }
    for(int i=n-1;i>=0;i--)
    if(checker(i))
    {
                Output();
                return 0;
                }
    printf("NO\n");
    return 0;
}