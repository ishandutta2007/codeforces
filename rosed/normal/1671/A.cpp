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
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>(s+1);
            int n=strlen(s+1);
            bool flag=1;
            for(int l=1;l<=n;++l)
            {
                int r=l;
                while(r<n&&s[r+1]==s[l]) ++r;
                //cout<<l<<' '<<r<<"!!"<<endl;
                if(l==r) flag=0;
                l=r;
            }
            if(!flag) cout<<"NO\n";
            else cout<<"YES\n";
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