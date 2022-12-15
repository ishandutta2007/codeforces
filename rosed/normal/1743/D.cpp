#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
void solve()
{
    int n;
    cin>>n;
    string s;cin>>s;
    reverse(s.begin(),s.end());
    while(n>1&&s.back()=='0') --n,s.pop_back();
    reverse(s.begin(),s.end());
    if(n==1)
    {
        cout<<s<<'\n';
        return;
    }
    int pos=-1;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            pos=i;break;
        }
    }
    if(pos==-1)
    {
        cout<<s<<'\n';
        return;
    }
    string ans=s;
    string ret=s;
    for(int t=0;t<pos;++t)
    {
        string tmp=s;
        for(int i=t,j=pos;j<n;++i,++j)
        {
            if(s[i]=='1') tmp[j]='1';

            // cout<<i<<' '<<j<<"!!!"<<endl;
        }
        // cout<<tmp<<"!!"<<endl;
        ans=max(ans,tmp);
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // red::__init();
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}
/*
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/