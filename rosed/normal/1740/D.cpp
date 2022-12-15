#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int mod=1e9+7;
const int inf=1e18;
const int N=2e5+10;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int tot=(n-1)*(m-1)+n+m-5;
    set<int> q;
    int now=k;
    bool ok=1;
    for(int i=1;i<=k;++i)
    {
        int x;cin>>x;
        if(x==now)
        {
            --now;
            while(now>0&&q.find(now)!=q.end())
            {
                q.erase(now);
                --now;
                ++tot;
            }
        }
        else
        {
            if(--tot<0) ok=0;
            q.insert(x);
        }
    }
    ok&=(now==0);
    if(ok) cout<<"YA\n";
    else cout<<"TIDAK\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}
/*


*/