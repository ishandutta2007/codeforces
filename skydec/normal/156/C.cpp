#include<stdio.h>
#include<cstring>
#define jsb 1000000007
using namespace std;
int f[105][2700];
char str[200];
int n,m,t;
int main()
{
    f[0][0]=1;
    for(int i=1;i<=100;i++)
    for(int j=1;j<=2600;j++)
    for(int k=1;k<=26;k++)
    if(k<=j)f[i][j]=(f[i][j]+f[i-1][j-k])%jsb;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",str+1);
              n=strlen(str+1);
              int tot=0;
              for(int i=1;i<=n;i++)tot+=str[i]-'a'+1;
              printf("%d\n",(f[n][tot]-1+jsb)%jsb);
              }
    return 0;
}