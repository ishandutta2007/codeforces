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
        cin>>n>>m;
        vector<int> rd(n+1);
        vector<set<int> > eg(n+1);
        vector<set<int> > eg2(n+1);
        for(int i=1;i<=m;++i)
        {
            int x,y;cin>>x>>y;
            ++rd[x],++rd[y];
            eg[x].insert(y);
            eg[y].insert(x);
        }
        int sum=0,st=0,ed=0;
        for(int i=1;i<=n;++i)
        {
            eg2[i]=eg[i];
            if(rd[i]&1)
            {
                if(!st) st=i;
                else ed=i;
                ++sum;
            }
        }
        if(!sum) st=1;
        int rt;
        vector<int> sta;
        vector<bool> vis(n+1);
        function<void(int)> dfs=[&](int now) -> void
        {
            while(!eg[now].empty())
            {
                int t=*eg[now].begin();
                eg[now].erase(t);
                eg[t].erase(now);
                //cout<<now<<' '<<t<<"!!"<<endl;
                dfs(t);
            }
            sta.emplace_back(now);
        };
        if(sum<=2)
        {
            dfs(st);
            reverse(sta.begin(),sta.end());
            cout<<sta.size()<<'\n';
            for(int t:sta) cout<<t<<' ';
            return;
        }
        for(int x=1;x<=n;++x)
        {
            rt=x;
            int ss=sum,tot=0;
            for(int i=1;i<=n;++i)
            {
                vis[i]=0;
            }
            for(int t:eg[x])
            {
                if(rd[t]&1)
                {
                    --ss;
                    vis[t]=1;
                    ++tot;
                }
            }
            if(rd[x]&1) --ss;
            if(ss>=2) continue;
            set<int> q;
            q=eg[x];
            if(ss==1)
            {
                //if(rd[x]%2!=1) continue;
                for(int i=1;i<=n;++i)
                {
                    if(vis[i])
                    {
                        eg[x].erase(i);
                        eg[i].erase(x);
                        continue;
                    }
                    if((rd[i]&1)&&i!=x) st=i;
                }
                for(int j=1;j<=n;++j) eg2[j]=eg[j];
                    sta.clear();
                dfs(st);

                
                reverse(sta.begin(),sta.end());
                int tmp=sta.size();
                //cout<<tmp<<"!!"<<endl;
                if(tmp!=m-tot+1)
                {
                    for(int j=1;j<=n;++j) eg[j]=eg2[j];
                    continue;
                }
                cout<<sta.size()+1+2*tot<<'\n';
                for(int t:sta) cout<<t<<' ';
                cout<<"-1 ";
                for(int t:q)
                {
                    if(vis[t])
                    {
                        cout<<t<<' '<<x<<' ';
                    }
                }
                return;
            }
            --tot;
            vector<int> qaq;
            for(int i=1;i<=n;++i)
            {
                if(vis[i]&&i!=x)
                {
                    qaq.emplace_back(i);
                    eg[x].erase(i);
                    eg[i].erase(x);
                    
                }
            }
            for(int i:qaq)
            {
                if(!vis[i]||i==x) continue;
                int st=i,ed=x;
                //cout<<x<<' '<<i<<"!!"<<endl;
                vis[i]=0;
                for(int j=1;j<=n;++j) eg2[j]=eg[j];
                eg[ed].insert(st);
                eg[st].insert(ed);
                sta.clear();
                dfs(st);
                reverse(sta.begin(),sta.end());
                int tmp=sta.size();
                //cout<<x<<' '<<i<<' '<<tmp<<"!!"<<endl;
                if(tmp!=m-tot+1)
                {
                    for(int j=1;j<=n;++j) eg[j]=eg2[j];
                        vis[i]=1;
                    continue;
                }
                cout<<sta.size()+1+2*tot<<'\n';
                for(int t:sta) cout<<t<<' ';
                cout<<"-1 ";
                for(int t:q)
                {
                    if(vis[t])
                    {
                        cout<<t<<' '<<x<<' ';
                    }
                }
                return;
            }
            
        }
        cout<<0<<'\n';
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