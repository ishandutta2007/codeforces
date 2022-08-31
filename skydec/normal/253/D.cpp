#include<stdio.h>
#include<cstring>
using namespace std;
int sum[405][405];
char str[405][405];
int u[27];
int n,m,ks;long long ans=0;
int calc(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&ks);
    for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(str[i][j]=='a');
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
            memset(u,0,sizeof u);
            int p=1;if(str[i][1]==str[j][1])u[str[i][1]-'a']=1;
            for(int k=2;k<=m;k++)
            {
                    while(calc(i,p,j,k)>ks&&p<k)
                    {
                      if(str[i][p]==str[j][p])
                      u[str[i][p]-'a']--;
                      p++;
                      }
                    if(str[i][k]==str[j][k])
                    {
                      ans+=1ll*u[str[i][k]-'a'];
                      u[str[i][k]-'a']++;
                      }
                    //if(i==2&&j==3)printf("%d %d\n",k,p);
                      }
                      }
    printf("%I64d\n",ans);
    return 0;
}