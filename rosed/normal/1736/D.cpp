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
    int n;cin>>n;
    string s;cin>>s;
    vector<int> tmp;
    int opt=0;
    for(int i=0;i<2*n;i+=2)
    {
        if(s[i]!=s[i+1])
        {
            tmp.emplace_back(i+1);
            if(s[i]-'0'!=opt)
            {
                ++tmp.back();
            }
            opt^=1;
        }
    }
    if(tmp.size()&1)
    {
        cout<<"-1\n";
        return;
    }
    cout<<tmp.size()<<'\n';
    for(int x:tmp) cout<<x<<' ';cout<<'\n';
    for(int l=1;l<=2*n;l+=2)
    {
        cout<<l<<" \n"[l==2*n-1];
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