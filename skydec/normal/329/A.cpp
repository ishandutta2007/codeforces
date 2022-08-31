#include<stdio.h>
#include<cstring>
using namespace std;
char str[105][105];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
            bool f2=0;
            for(int j=1;j<=n;j++)if(str[i][j]=='.')f2=1;
            flag&=f2;
            }
    if(flag)
    {
            for(int i=1;i<=n;i++)
            {
                    for(int j=1;j<=n;j++)
                    if(str[i][j]=='.')
                    {
                                      printf("%d %d\n",i,j);
                                      break;
                                      }
            }
            return 0;
            }
    flag=1;
    for(int j=1;j<=n;j++)
    {
            bool f2=0;
            for(int i=1;i<=n;i++)if(str[i][j]=='.')f2=1;
            flag&=f2;
            }
    if(flag)
    {
            for(int j=1;j<=n;j++)
            {
                    for(int i=1;i<=n;i++)
                    if(str[i][j]=='.'){printf("%d %d\n",i,j);break;}
            }
            return 0;
            }
    printf("-1\n");
    return 0;
}