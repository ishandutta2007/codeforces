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
    const int N=2e6+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    inline void main()
    {
        int n;cin>>n;
        vector a(n,vector<int>());
        vector<int> b(n);
        for(int i=0;i<n;++i)
        {
            int s;cin>>s;
            a[i].resize(s);
            b[i]=s;
            for(int j=0;j<s;++j) cin>>a[i][j];
        }
        int m;cin>>m;
        map<vector<int>,int> ok;
        map<vector<int>,int> vis;
        for(int i=0;i<m;++i)
        {
            vector<int> t(n);
            for(int i=0;i<n;++i) cin>>t[i],--t[i];
            ok[t]=1;
        }
        vector<int> ans(n),tmp(n),st(n);int sum=0;
        typedef pair<int,vector<int> > pr;
        priority_queue<pr,vector<pr>,greater<pr> > q;
        int maxn=0;
        function<void()> spfa=[&]() -> void
        {
            q.push(pr(sum,st));
            vis[st]=1;
            while(!q.empty())
            {
                int val=q.top().first;
                vector now=q.top().second;
                q.pop();
                for(int k=0;k<n;++k)
                {
                    if(now[k]>0)
                    {
                        --now[k];
                        int tval=val-a[k][now[k]+1]+a[k][now[k]];
                        if(!ok[now])
                        {
                            if(tval>maxn) maxn=tval,ans=now;
                        }
                        else if(!vis[now])
                        {
                            q.push(pr(tval,now));
                            vis[now]=1;
                        }
                        ++now[k];
                    }
                }
            }
        };
        for(int i=0;i<n;++i) st[i]=b[i]-1,sum+=a[i][b[i]-1];
        if(ok[st]) spfa();
        else ans=st;
        // cout<<maxn<<"!!"<<endl;
        for(int x:ans) cout<<x+1<<' ';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int qwq=1;// cin>>qwq;
    while(qwq--)
    red::main();
    return 0;
}
/*
1 2 3 3
1 3 2 3
1 3 3 2
3 1 2 3
3 1 3 2
3 3 1 2
*/