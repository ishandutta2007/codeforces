#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=998244353,inv2=499122177,inf=2e18;
    void __init(int n=2000) {}
    
    inline void main()
    {
        string s;
        cin>>s;
        int n=s.length();
        vector<int> a(n+1);
        bool ans=0;
        for(int tmp=0;tmp<8;++tmp)
        {
            for(int i=1;i<=n;++i)
            {
                if(s[i-1]=='A') a[i]=tmp&1;
                if(s[i-1]=='B') a[i]=tmp&2;
                if(s[i-1]=='C') a[i]=tmp&4;
            }
            bool flag=1;
            int sum=0;
            for(int i=1;i<=n;++i)
            {
                if(a[i]) ++sum;
                else --sum;
                if(sum<0) flag=0;
            }
            if(sum!=0) flag=0;
            ans|=flag;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
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

*/