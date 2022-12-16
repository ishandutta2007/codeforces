#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e5+10,inf=2e9,mod=1e9+7;
    int n,m;
    int d[N];
    vector<int> e[N];
    int num[N];
    typedef pair<int,int> p;
    p st[N];
    int top;
    inline void dfs(int x,int sum)
    {
        int tot=e[d[x]+1].size();
        for(int i=num[d[x]+1];i<tot;++i)
        {
            --sum;
            if(sum<0) break;
            int t=e[d[x]+1][i];
            st[++top]=p(x,t);
            ++num[d[x]+1];
            dfs(t,m-1);
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            int x;cin>>x;
            d[i]=x;
            e[x].push_back(i);
        }
        num[0]=1;
        if(!e[0].size())
        {
            cout<<"-1\n";return;
        }
        dfs(e[0][0],m);
        for(int i=0;i<=n;++i)
        {
            if(num[i]!=e[i].size())
            {
                cout<<"-1\n";return;
            }
        }
        cout<<top<<'\n';
        for(int i=1;i<=top;++i)
        {
            cout<<st[i].first<<' '<<st[i].second<<'\n'; 
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
ans[k][n]=k! \sum_{i=1}^{n} C(n-i+k,k)f[k][i]
*/