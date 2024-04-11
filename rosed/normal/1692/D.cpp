#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int h,m,h0,m0,x;
    char s[N];
    inline bool check(int x,int y)
    {
        int xx=x%10*10+x/10;
        return xx==y;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>s>>x;
            h0=(s[0]-'0')*10+s[1]-'0';
            m0=(s[3]-'0')*10+s[4]-'0';
            h=h0,m=m0;
            int ans=0;
            bool flag=0;
            while(!flag||(h0!=h||m0!=m))
            {
               // cout<<h<<' '<<m<<"!!"<<endl;
                flag=1;
                if(check(h,m)) ++ans;
                m+=x;
                h+=m/60;
                m%=60;
                h%=24;
            }
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}