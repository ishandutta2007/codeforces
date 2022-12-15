#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
void solve()
{
    vector mp(8,vector<char>(8));
    bool flag=0;
    for(int i=0;i<8;++i)
    {
        int sum=0;
        for(int j=0;j<8;++j)
        {
            char ch;cin>>ch;
            if(ch=='R') ++sum;
        }
        if(sum==8) flag=1;
    }
    if(flag) cout<<"R\n";
    else cout<<"B\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}