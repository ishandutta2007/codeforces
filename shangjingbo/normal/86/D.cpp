#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 200005

struct node
{
    int l,r,lid,id;
}inter[maxn];
int n,m,a[maxn];
int cnt[1000001];
long long out[maxn];

inline bool cmp(const node &a,const node &b)
{
    return a.lid<b.lid || a.lid==b.lid && a.r>b.r;
}

int main()
{
    scanf("%d%d",&n,&m);
    int Size=(int)sqrt(n)+2;
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for (int i=0;i<m;++i)
    {
        scanf("%d%d",&inter[i].l,&inter[i].r);
        --inter[i].l;
        --inter[i].r;
        inter[i].lid=inter[i].l/Size;
        inter[i].id=i;
    }
    
    sort(inter,inter+m,cmp);
    memset(cnt,0,sizeof(cnt));
    int l=0,r=-1;
    long long ans=0;
    for (int i=0;i<m;++i)
    {
        int ll=inter[i].l,rr=inter[i].r;
        while (r<rr)
        {
            ++r;
            int x=a[r];
            ans+=x*(cnt[x]*2LL+1);
            ++cnt[x];
        }
        while (r>rr)
        {
            int x=a[r];
            ans-=x*(cnt[x]*2LL-1);
            --cnt[x];
            --r;
        }
        while (ll<l)
        {
            --l;
            int x=a[l];
            ans+=x*(cnt[x]*2LL+1);
            ++cnt[x];
        }
        while (ll>l)
        {
            int x=a[l];
            ans-=x*(cnt[x]*2LL-1);
            --cnt[x];
            ++l;
        }
        
        out[inter[i].id]=ans;
    }
    
    for (int i=0;i<m;++i)
        printf("%I64d\n",out[i]);
    
    return 0;
}