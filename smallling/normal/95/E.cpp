#include<cstdio>
#include<algorithm>

#define inf 1000000000
#define N 100005

using namespace std;

int s,n,m,fa[N],si[N],b[N],f[N],ans,x,y;

int get(int o)
{
    if(fa[o]==o)return o;
    return fa[o]=get(fa[o]);
}
bool check(int o)
{
    while(o)
    {
        if (o%10!=7&&o%10!=4) return 0;
        o/=10;
    }
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),fa[get(x)]=get(y);
    for(int i=1;i<=n;i++)si[get(i)]++;
    for(int i=1;i<=n;i++)b[si[i]]++;
    f[0]=0;
    for(int i=1;i<=n;i++)
        f[i]=inf;
    ans=inf;
    for(int i=1;i<=n;i++)
    {
        if(b[i])
        {
            for(int j=1;j<=b[i];j*=2)
            {
                int gt=j*i;
                for (int k=n-gt;k>=0;k--)f[k+gt]=min(f[k+gt],f[k]+j);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(check(i))ans=min(ans,f[i]-1);
    if(ans>n)ans=-1;
    printf("%d\n",ans);
}