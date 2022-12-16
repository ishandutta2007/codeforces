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
    const int N=4e5+10,mod=998244353,inf=2e9;
    int n,m,tot;
    char s[N];
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;tot=0;
            cin>>(s+1);
            for(int i=1;i<=n;++i) a[i]=0;
            if(!m)
            {
                cout<<(s+1)<<'\n';
                for(int i=1;i<=n;++i) cout<<0<<" \n"[i==n];
                continue;
            }
            for(int i=1;i<=n;++i)
            {
                if(tot&1)
                {
                    if(s[i]=='1') s[i]='0';
                    else s[i]='1';
                }
                if(m<=0||i==n) continue;
                if(s[i]=='1')
                {
                    if(m%2==1)
                    {
                        --m;++a[i];++tot;
                    }
                }
                else
                {
                    if(m%2==0)
                    {
                        --m;++a[i];++tot;
                    }
                    s[i]='1';
                }
            }
            a[n]+=m;
            cout<<(s+1)<<'\n';
            for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
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