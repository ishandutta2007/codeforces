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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n;
    char s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>(s+1);
            n=strlen(s+1);
            int s1=0,s2=0,s3=0,s4=0,s5=0,s6=0;
            for(int i=1;i<=n;++i)
            {
                if(s[i]=='0') ++s4;
                if(s[i]=='1') ++s5;
                if(s[i]=='?') ++s6;
            }
            int sum=0;
            for(int i=1;i<=n;++i)
            {
                if(s[i]=='0') --s4;
                if(s[i]=='1') --s5;
                if(s[i]=='?') --s6;
                if(!s5&&!s1) ++sum;
                if(s[i]=='0') ++s1;
                if(s[i]=='1') ++s2;
                if(s[i]=='?') ++s3;
            }
            cout<<sum<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


*/