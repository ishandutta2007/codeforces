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
        string s;cin>>s;
        int n=s.length();
        int t1=s[0]-'a',t2=s[n-1]-'a';
        vector<int> a;
        if(t1<=t2)
        {
            for(int c=t1;c<=t2;++c)
            {
                int pos=-1;
                for(int i=0;i<n;++i)
                {
                    if(s[i]==c+'a') a.emplace_back(i+1);
                }       
            }
        }
        else
        {
            for(int c=t1;c>=t2;--c)
            {
                int pos=-1;
                for(int i=0;i<n;++i)
                {
                    if(s[i]==c+'a') a.emplace_back(i+1);
                }
            }
        }
        cout<<abs(t1-t2)<<' '<<a.size()<<'\n';
        for(int x:a) cout<<x<<' ';
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