#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
#define INF 1000000007
int n,m,f[N],s[N],t[N],S=INF;
int fa(int x){return f[x]==x?x:(f[x]=fa(f[x]));}
bool ff(int x)
{
    for(;x;x/=10)if(x%10!=4&&x%10!=7)return 0;
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1,x,y;i<=m;i++)
        scanf("%d%d",&x,&y),
        f[fa(x)]=fa(y);
    for(int i=1;i<=n;i++)s[fa(i)]++;
    for(int i=1;i<=n;i++)t[s[i]]++;
    for(int i=1;i<=n;i++)f[i]=INF;
    for(int i=1;i<=n;i++)if(t[i])
    {
        int k=t[i];
        for(int h=1;k;h+=h)
        {
            k-=(h=min(h,k));
            int hi=h*i;
            for(int j=n-hi;j>=0;j--)
                f[j+hi]=min(f[j+hi],f[j]+h);
        }
    }
    for(int i=1;i<=n;i++)if(ff(i))S=min(S,f[i]);
    if(S==INF)puts("-1");else printf("%d\n",S-1);
    return 0;
}