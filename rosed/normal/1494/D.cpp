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
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;
        cin>>m;
        vector a(m+1,vector<int>(m+1));
        priority_queue<int,vector<int>,greater<int> > q;
        typedef pair<int,int> pr;
        vector<set<pr> > vis(5000+1);
        vector<bool> ok(100000+1);
        vector<int> id(100000+1),c(100000+1),f(100000+1);
        vector<vector<int> > eg(100001);
        vector<int> g(100000+1),ff(100000+1);
        int maxn=0;
        n=m;
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=m;++j)
            {
                cin>>a[i][j];
                maxn=max(maxn,a[i][j]);
                if(i==j)
                {
                    c[i]=a[i][i];
                    ff[i]=i;
                    continue;
                }
                if(!ok[a[i][j]]&&i!=j)
                {
                    q.push(a[i][j]);
                    ok[a[i][j]]=1;
                }
                if(i<j)
                {
                    vis[a[i][j]].insert(pr(i,j));
                }
            }
        }
        function<int(int)> find=[&](int k) -> int
        {
            return f[k]==k?k:f[k]=find(f[k]);
        };
        while(!q.empty())
        {
            int now=q.top();
            q.pop();
            set<int> qq;
            set<int> qqq;
            auto it=vis[now].begin();
            while(it!=vis[now].end())
            {
                int x=(*it).first,y=(*it).second;
                qqq.insert(x);
                qqq.insert(y);
                x=ff[x],y=ff[y];
                qq.insert(x);
                qq.insert(y);
                f[x]=x;f[y]=y;
                ++it;
            }
            it=vis[now].begin();
            while(it!=vis[now].end())
            {
                int x=(*it).first,y=(*it).second; x=ff[x],y=ff[y];
                f[find(x)]=find(y);
                ++it;
            }

            auto it1=qq.begin();
            while(it1!=qq.end())
            {
                int x=*it1;
                if(find(x)==x)
                {
                    ++n;
                    c[n]=now;
                    g[x]=n;
                }
                ++it1;
            }

            it1=qq.begin();
            while(it1!=qq.end())
            {
                int x=*it1;
                eg[x].emplace_back(g[find(x)]);
                ++it1;
            }
            auto it2=qqq.begin();
            while(it2!=qqq.end())
            {
                int x=*it2;
                ff[x]=g[find(ff[x])];
                ++it2;
            }
        }
        cout<<n<<'\n';
        for(int i=1;i<=n;++i) cout<<c[i]<<" \n"[i==n];
        cout<<n<<'\n';
        for(int i=1;i<n;++i)
        {
            for(int t:eg[i]) cout<<i<<' '<<t<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/