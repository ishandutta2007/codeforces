#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
char str[MAXN];
int fr[MAXN][27];
int n;
void init()
{
     for(int i=n;i>=1;i--)
     {
             for(int j=1;j<=26;j++)fr[i][j]=fr[i+1][j];
             fr[i][str[i]-'a'+1]=i;
             }
}
int main()
{
    scanf("%s",str+1);n=strlen(str+1);
    init();
    for(int now=1;now<=n;now++)
    {
            for(int i=26;i>=1;i--)
            if(fr[now][i])
            {
                          putchar(i+'a'-1);
                          now=fr[now][i];
                          break;
                          }
                          }
    return 0;
}