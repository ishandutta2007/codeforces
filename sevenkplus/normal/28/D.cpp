#include<cstdio>
#include<algorithm>
using namespace std;
#define N 111111
#define inf 1000000007
int n,v[N],w[N],x[N],y[N],p[N],a[N],f[N+N],g[N+N],q[N],S=0,L=0,A[N];
inline bool cmp(const int&a,const int&b){return p[a]<p[b]||p[a]==p[b]&&a<b;}
inline void upd(int a,int b,int c){if(b>f[a])f[a]=b,g[a]=c;}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",v+i,w+i,x+i,y+i),
        a[i]=i,p[i]=w[i]+x[i]+y[i],q[i]=-1;
    sort(a,a+n,cmp);
    for(int l=0,r=0;l<n;l=r)
    {
        for(;r<n&&p[a[l]]==p[a[r]];r++);
        for(int i=l;i<r;i++)
            if(x[a[i]]==0)upd(y[a[i]],v[a[i]],a[i]);else
            if(f[w[a[i]]+y[a[i]]]>0)
                q[a[i]]=g[w[a[i]]+y[a[i]]],
                upd(y[a[i]],f[w[a[i]]+y[a[i]]]+v[a[i]],a[i]);
        if(f[0]>S)
        {
            L=0;S=f[0];
            for(int u=g[0];u!=-1;u=q[u])A[L++]=u;
        }
        for(int i=l;i<r;i++)f[y[a[i]]]=0;
    }
    printf("%d\n",L);
    for(int i=L-1;i>=0;i--)printf("%d%c",A[i]+1,i?' ':'\n');
    return 0;
}