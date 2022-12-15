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
    int n;
    cin>>n;
    int sum=0;
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        sum+=2*(x+y);
        if(x>y) swap(x,y);
        // q.push(x);
        q.push(y);
    }
    // int tot=0;
    while(q.size()>1)
    {
        int x=q.top();q.pop();
        // int y=q.top();q.pop();
        // tot+=2*x;
        // cout<<x<<"!!"<<endl;
        sum-=2*x;
        // if(x!=y) q.push(x-y);
    }
    cout<<sum<<'\n';
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