#include<stdio.h>
#include<cstring>
#define MAXN 1100000
#define jsb 1000000007
using namespace std;
int n;
int f[MAXN][4][2];
char str[MAXN];
void ADD(int &x,int y){x+=y;x%=jsb;}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    if(str[1]=='*')
    {
                   f[1][3][0]=1;
                   }
    else if(str[1]=='?')
    {
         f[1][0][0]=f[1][1][0]=f[1][2][0]=f[1][3][0]=1;
         }
    else f[1][str[1]-'0'][0]=1;
    for(int i=1;i<n;i++)
    for(int j=0;j<4;j++)
    for(int k=0;k<2;k++)
    {
            if(str[i]=='*'&&j!=3)continue;
            if(str[i]<='9'&&str[i]>='0')
            if(str[i]-48!=j)continue;
            if(j==2&&!k)continue;
            if(j==3)
            {
                    for(int s=1;s<=2;s++)ADD(f[i+1][s][1],f[i][j][k]);
                    ADD(f[i+1][3][1],f[i][j][k]);
                    }
            else
            {
                if(k>j)continue;
                if(k==j)
                {
                        for(int s=0;s<=1;s++)ADD(f[i+1][s][0],f[i][j][k]);
                        }
                else if(k+1==j)
                {
                     ADD(f[i+1][3][0],f[i][j][k]);
                     }
                     }
                     }
    int ans=0;
    for(int j=0;j<=3;j++)
    for(int k=0;k<2;k++)
    {
            if(str[n]=='*'&&j!=3)continue;
            if(str[n]<='9'&&str[n]>='0')
            if(str[n]-48!=j)continue;
            if(j<3&&k<j)continue;
            if(j<3)
            if(k>j)continue;
            ADD(ans,f[n][j][k]);
            }
    printf("%d\n",ans);
    return 0;
}