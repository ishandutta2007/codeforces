#include<stdio.h>
#include<cstring>
#define MAXN 210000
using namespace std;
typedef long double ld;
char a[MAXN],b[MAXN];
int n;long double ans=0;
ld head[30][MAXN];
ld sum[30][MAXN];
void init()
{
     for(int i=1;i<=n;i++)
     {
             for(int j=1;j<=26;j++)
             head[j][i]=head[j][i-1],sum[j][i]=sum[j][i-1];
             int u=b[i]-'A'+1;
             head[u][i]+=i;
             sum[u][i]+=n-i+1;
             }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",a+1);
    scanf("%s",b+1);
    init();
    for(int i=1;i<=n;i++)
    {
            int u=a[i]-'A'+1;
            ans+=head[u][i]*1.*(n-i+1);
            ans+=(sum[u][n]-sum[u][i])*1.*i;
            }
    long double all=0;
    for(int i=1;i<=n;i++)all+=(n-i+1)*1.*(n-i+1);
    printf("%.8lf\n",(double)(ans/all));
    return 0;
}