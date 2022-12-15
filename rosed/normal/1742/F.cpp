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
    int n;
    cin>>n;
    typedef array<int,26> node;
    vector<int> sum(3);
    bool flag1=0,flag2=0;
    for(int i=1;i<=n;++i)
    {
        int opt,k;
        string s;
        cin>>opt>>k>>s;
        for(char ch:s)
        {
            if(ch!='a')
            {
                if(opt==1) flag1=1;
                else flag2=1;
            }
            else sum[opt]+=k;
        }
        if(flag2||(!flag1&&sum[1]<sum[2])) cout<<"YES\n";
        else cout<<"NO\n";
    }
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
aaabb
aaaaaaaaaaaabbbccc
*/