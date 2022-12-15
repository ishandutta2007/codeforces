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
    int n,m;
    cin>>n>>m;
    string s;cin>>s;
    int p=1;
    for(int i=0;i<n;++i)
    {
        if(s[i]>s[i%p]) break;
        if(s[i]<s[i%p]) p=i+1;
    }
    for(int i=0;i<m;++i) cout<<s[i%p];
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