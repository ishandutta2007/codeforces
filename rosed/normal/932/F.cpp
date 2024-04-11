#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e5+10,mod=1e9+7,inf=2e9;
    int n;
    int up=1e5,delta=up+1;
    int a[N],b[N];
    vector<int> eg[N];
    int rt[N];
    int dp[N];
    struct node
    {
        int k,b;
    };
    struct lctree
    {
        node ans[N*20];
        int son[N*20][2];
        int tot;
        inline int calc(node tmp,int x)
        {
            return tmp.k*x+tmp.b;
        }
        inline void update(int l,int r,int &p,node tmp)
        {
            if(!p)
            {
                p=++tot;
                ans[p]=tmp;
                return;
            }
            if(calc(tmp,mid-delta)<calc(ans[p],mid-delta)) swap(ans[p],tmp);
            if(calc(tmp,l-delta)<calc(ans[p],l-delta)) update(l,mid,son[p][0],tmp);
            if(calc(tmp,r-delta)<calc(ans[p],r-delta)) update(mid+1,r,son[p][1],tmp);
        }
        inline void merge(int l,int r,int &x,int y)
        {
            if(!x||!y){x=x|y;return;}
            if(calc(ans[x],mid)>calc(ans[y],mid)) swap(ans[x],ans[y]);
            if(l==r) return;
            merge(l,mid,son[x][0],son[y][0]);
            merge(mid+1,r,son[x][1],son[y][1]);
            update(l,r,x,ans[y]);
        }
        inline void query(int pos,int l,int r,int p,int &tmp)
        {
            if(!p) return;
            tmp=min(tmp,calc(ans[p],pos-delta));
            if(l==r) return;
            if(pos<=mid) query(pos,l,mid,son[p][0],tmp);
            else query(pos,mid+1,r,son[p][1],tmp);
        }
    }T;
    inline void dfs(int now,int fa)
    {
        bool flag=0;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            T.merge(1,2*up+1,rt[now],rt[t]);
            flag=1;
        }
        dp[now]=inf*inf;
        T.query(a[now]+delta,1,up+delta,rt[now],dp[now]);
        if(!flag) dp[now]=0;
        node tmp=(node){b[now],dp[now]};
        T.update(1,up+delta,rt[now],tmp);
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i) cin>>b[i];
        for(int i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            eg[x].emplace_back(y);
            eg[y].emplace_back(x);
        }
        dfs(1,0);
        for(int i=1;i<=n;++i) cout<<dp[i]<<" \n"[i==n];
    }
}
signed main()
{
    //freopen("data.in","r",stdin);
    //freopen("red.out","w",stdout);
    red::main();
    return 0;
}
/*
dp[now]=dp[t]+a[now]*b[t];

*/