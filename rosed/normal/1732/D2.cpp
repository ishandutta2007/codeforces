#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
void solve()
{
    int n;
    cin>>n;
    set<int> q;
    map<int,vector<int> > g;//x
    map<int,set<int> > f;//
    map<int,int> lst;
    for(int i=1;i<=n;++i)
    {
        char ch;cin>>ch;
        int x;cin>>x;
        if(ch=='+')
        {
            q.insert(x);
            for(int y:g[x]) f[y].erase(x);
        }
        else if(ch=='-')
        {
            q.erase(x);
            for(int y:g[x]) f[y].insert(x);
        }
        else
        {
            if(f[x].size())
            {
                cout<<(*f[x].begin())<<'\n';
            }
            else
            {
                for(int i=max(x,lst[x]);;i+=x)
                {
                    if(q.count(i)==0)
                    {
                        lst[x]=i;
                        cout<<i<<'\n';
                        break;
                    }
                    else g[i].emplace_back(x);
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/