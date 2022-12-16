#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,mod=201314,inf=2e9;
    int n,idx;
    vector<int> e[N];
    char ch[N];
    int num[N];
    map<int,int> q;
    int c[N],tot;
    bool vis[N];
    struct edge
    {
        int nxt,to,id,g;
    }a[N<<2];
    int head[N<<1],cnt=1;
    inline void link(int x,int y,int id)
    {
        a[++cnt].nxt=head[x];
        a[cnt].to=y;
        a[cnt].id=id;
        a[cnt].g=1;
        head[x]=cnt;
    }
    inline void dfs(int now,int pre)
    {
        vis[now]=1;
        for(int i=head[now];i;i=head[now])
        {
            head[now]=a[i].nxt;
            if(a[i].g)
            {
                int t=a[i].to;
                a[i].g=a[i^1].g=0;
                dfs(t,i);
            }
            
        }
        if(pre) ch[a[pre].id]="RL"[now<=tot];
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>num[i];
            for(int j=1;j<=num[i];++j)
            {
                int x;cin>>x;
                e[i].push_back(x);
                q[x]++;
                c[++tot]=x;
            }
        }
        sort(c+1,c+tot+1);
        tot=unique(c+1,c+tot+1)-c-1;
        bool flag=0;
        for(int i=1;i<=tot;++i)
        {
            if(q[c[i]]%2==1) flag=1;
        }
        if(flag)
        {
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<num[i];++j)
            {
                e[i][j]=lower_bound(c+1,c+tot+1,e[i][j])-c;
                ++idx;
                link(e[i][j],i+tot,idx);
                link(i+tot,e[i][j],idx);
            }
        }
        for(int i=1;i<=tot+n;++i) if(!vis[i])
        {
            dfs(i,0);
        }
        idx=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=num[i];++j)
            {
                cout<<ch[++idx];
            }
            cout<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}