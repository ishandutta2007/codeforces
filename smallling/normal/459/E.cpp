#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
    int u,v,w;
}a[300030];

int f[300030],same[300030],val[300030],ans,n,m,o;

inline int cmp(const lhy &a,const lhy &b)
{
    return a.w<b.w;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        o=1;
        same[1]=a[i].v;
        val[1]=f[a[i].u]+1;
        while(a[i].w==a[i+1].w)i++,same[++o]=a[i].v,val[o]=f[a[i].u]+1;
        for(int j=1;j<=o;j++)
            f[same[j]]=max(f[same[j]],val[j]);
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]);
    printf("%d",ans);
}