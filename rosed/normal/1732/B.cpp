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
    string s;
    cin>>s;
    int sum=0;
    bool opt=0;
    for(int i=0;i<n-1;++i)
    {
        if(s[i]=='1'&&s[i+1]=='0') opt=1,++sum;
        if(s[i]=='0'&&s[i+1]=='1'&&opt) ++sum;
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