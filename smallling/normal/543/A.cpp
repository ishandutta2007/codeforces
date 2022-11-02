#include<cstdio> 

using namespace std;

int n,m,b,mo,ans;
int a[1010],f[1010][1010];

int main()
{
    scanf("%d%d%d%d",&n,&m,&b,&mo);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k+a[i]<=b;k++)
                (f[j+1][k+a[i]]+=f[j][k])%=mo;
    for(int i=0;i<=b;i++)(ans+=f[m][i])%=mo;
    printf("%d",ans);
}