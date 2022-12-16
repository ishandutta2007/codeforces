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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,st,ed;
    int a[N];
    int dp[N];
    typedef pair<int,int> pr;
    priority_queue<pr,vector<pr>,greater<pr> > q1;
    priority_queue<pr> q2;
    struct segment_tree
    {
        int ans[N<<2];
        inline void build(int l,int r,int p)
        {
            ans[p]=inf;
            if(l==r)  return;
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
        }
        inline void update(int pos,int l,int r,int p,int k)
        {
            if(l==r)
            {
                ans[p]=k;
                return;
            }
            if(pos<=mid) update(pos,l,mid,ls(p),k);
            if(pos>mid) update(pos,mid+1,r,rs(p),k);
            ans[p]=min(ans[ls(p)],ans[rs(p)]);
        }
        inline int query(int tl,int tr,int l,int r,int p)
        {
            if(tl<=l&&r<=tr)
            {
                return ans[p];
            }
            if(tr<=mid) return query(tl,tr,l,mid,ls(p));
            if(tl>mid) return query(tl,tr,mid+1,r,rs(p));
            return min(query(tl,tr,l,mid,ls(p)),query(tl,tr,mid+1,r,rs(p)));
        }
    }T;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int TT;cin>>TT;
        while(TT--)
        {
            cin>>n>>st>>ed;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                dp[i]=inf;
            }
            dp[st]=0;
            bool opt=0;
            while("miao")
            {
                bool flag=0;
                T.build(1,n,1);
                {
                    while(!q1.empty()) q1.pop();
                    for(int i=1;i<=n;++i)
                    {
                        while(!q1.empty())
                        {
                            int now=q1.top().first;
                            if(now<i)
                            {
                                int j=q1.top().second;
                                q1.pop();
                                T.update(j,1,n,1,inf);
                            }
                            else break;
                        }
                        int lst=dp[i];
                        dp[i]=min(dp[i],T.query(max(1ll,i-a[i]),i,1,n,1)+1);
                        if(dp[i]!=lst) flag=1;
                        T.update(i,1,n,1,dp[i]);
                        q1.push(pr(i+a[i],i));
                    }
                }
                T.build(1,n,1);
                {
                    while(!q2.empty()) q2.pop();
                    for(int i=n;i>=1;--i)
                    {
                        while(!q2.empty())
                        {
                            int now=q2.top().first;
                            if(now>i)
                            {
                                int j=q2.top().second;
                                q2.pop();
                                T.update(j,1,n,1,inf);
                            }
                            else break;
                        }
                        int lst=dp[i];
                        dp[i]=min(dp[i],T.query(i,min(n,i+a[i]),1,n,1)+1);
                        if(dp[i]!=lst) flag=1;
                        T.update(i,1,n,1,dp[i]);
                        q2.push(pr(i-a[i],i));
                    }
                }
                //for(int i=1;i<=n;++i) cout<<dp[i]<<" \n"[i==n];
                if(!flag) break;
            }
            cout<<dp[ed]<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
5
1 2
2 3
3 4
3 5

*/