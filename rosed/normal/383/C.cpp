#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N];
    vector<int> eg[N];
    struct BIT
    {
        int tr[N];
        inline void update(int x,int k)
        {
           for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
        }
        inline int query(int x)
        {
           int sum=0;
           for(int i=x;i;i-=lowbit(i)) sum+=tr[i];
           return sum;
        }
    }T[2];
    int dep[N],tl[N],tr[N],idx;
    int st[2][N],top[2];
    inline void dfs(int now,int fa)
    {
        dep[now]=dep[fa]+1;
        int b=dep[now]&1;
        tl[now]=++idx;
        st[b][++top[b]]=idx;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
        }
        tr[now]=idx;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(int i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            eg[x].push_back(y);
            eg[y].push_back(x);
        }
        dfs(1,0);
        for(int i=1;i<=m;++i)
        {
            int opt;
            cin>>opt;
            if(opt==1)
            {
                int x,y;
                cin>>x>>y;
                int b=dep[x]&1;
                int ql=lower_bound(st[b]+1,st[b]+top[b]+1,tl[x])-st[b];
                int qr=upper_bound(st[b]+1,st[b]+top[b]+1,tr[x])-st[b]-1;
                if(ql<=qr)
                {
                    T[b].update(ql,y);
                    T[b].update(qr+1,-y);
                }
                b^=1;
                ql=lower_bound(st[b]+1,st[b]+top[b]+1,tl[x])-st[b];
                qr=upper_bound(st[b]+1,st[b]+top[b]+1,tr[x])-st[b]-1;
                if(ql<=qr)
                {
                    T[b].update(ql,-y);
                    T[b].update(qr+1,y);
                }
            }
            else
            {
                int x;cin>>x;
                int b=dep[x]&1;
                int pos=lower_bound(st[b]+1,st[b]+top[b]+1,tl[x])-st[b];
                cout<<T[b].query(pos)+a[x]<<'\n';
            }
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
4 4
zzzz
z.z.
.zzz
zzzz

*/