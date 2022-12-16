#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=1e15,mod=1e9+7;
    int n;
    int a[N];
    char s[N];
    int cnt[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>(s+1);
            n=strlen(s+1);
            for(int i=n;i>=1;--i)
            {
                ++cnt[s[i]];
            }
            int st=1;
            for(int i=1;i<=n;++i)
            {
                if(cnt[s[i]]>1)
                {
                    --cnt[s[i]];
                }
                else
                {
                    st=i;break;
                }
            }
            for(int i=st;i<=n;++i) cout<<s[i];
            for(int i='a';i<='z';++i) cnt[i]=0;
            cout<<'\n';
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