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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,m;
    char s[N];
    bool flag;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            cin>>(s+1);flag=1;
            s[0]='W';s[n+1]='W';
            for(int i=1;i<=n&&flag;++i)
            {
                if(s[i]=='W') continue;
                bool t1=0,t2=0;
                int l=i,r=i;
                while(s[r+1]!='W') ++r;
                if(r-l+1==1) flag=1;
                for(int k=l;k<=r;++k)
                {
                    if(s[k]=='B') t1=1;
                    if(s[k]=='R') t2=1;
                }
                if(!t1||!t2) flag=0;
                i=r;
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
1 2 3 4

*/