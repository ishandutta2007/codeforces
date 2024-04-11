#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m,ans;
    struct node
    {
        int a,b,c;
    }q[N],f[N];
    int c[N],num; 
    inline bool cmp1(node a,node b)
    {
        return a.b>b.b;
    }
    inline bool cmp2(node a,node b)
    {
        return a.c<b.c;
    }
    int tr[N];
    inline void update(int x,int k)
    {
        for(int i=x;i<=num;i+=lowbit(i)) tr[i]+=k;
    }
    inline int query(int x)
    {
        int sum=0;
        for(int i=x;i;i-=lowbit(i)) sum+=tr[i];
        return sum;
    }
    inline void solve1(int l,int r)
    {
        if(l==r) return;
        solve1(l,mid);solve1(mid+1,r);
        int tl=l,tr=l-1;
        for(int i=mid+1;i<=r;++i)
        {
            while(tr<mid&&q[tr+1].c-q[i].c<=m)
            {
                ++tr;
                update(q[tr].a,1);
            }
            while(tl<=mid&&q[i].c-q[tl].c>m)
            {
                update(q[tl].a,-1);
                ++tl;
            }
            int ll=lower_bound(c+1,c+num+1,c[q[i].a]-q[i].b)-c;
            int rr=upper_bound(c+1,c+num+1,c[q[i].a]+q[i].b)-c-1;
            if(rr>=ll) ans+=query(rr)-query(ll-1);
        }
        while(tl<=tr)
        {
            update(q[tl].a,-1);
            ++tl;
        }
        sort(q+l,q+r+1,cmp2);
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            cin>>q[i].a>>q[i].b>>q[i].c;
            c[++num]=q[i].a;
        }
        sort(c+1,c+num+1);
        num=unique(c+1,c+num+1)-c-1;
        for(int i=1;i<=n;++i)
        {
            q[i].a=lower_bound(c+1,c+num+1,q[i].a)-c;
        }
        sort(q+1,q+n+1,cmp1);
        solve1(1,n);
        cout<<ans<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
1
1 2 3 4

*/