#include <cstdio>
#include <cstring>
#define maxn 100005

int n,m,k;
int l[maxn],r[maxn],c[maxn];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<m;++i)
        scanf("%d%d%d",&l[i],&r[i],&c[i]);
    
    long long ans=0;
    for (int i=0;i<k;++i)
    {
        int x;
        scanf("%d",&x);
        for (int j=0;j<m;++j)
        if (l[j]<=x && x<=r[j])
            ans+=x-l[j]+c[j];
    }
    printf("%I64d\n",ans);
    
    return 0;
}