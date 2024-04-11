#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;cin>>n;
        string s;cin>>s;
        vector<int> a;
        for(int i=n-1;i>=0;--i)
        {
            if(s[i]=='0')
            {
                int num=s[i-1]-'0'+(s[i-2]-'0')*10;
                a.emplace_back(num);
                i-=2;
            }
            else
            {
                a.emplace_back(s[i]-'0');
            }
        }
        reverse(a.begin(),a.end());
        for(int x:a) cout<<(char)(x-1+'a');
        cout<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/