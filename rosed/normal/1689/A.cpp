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
    int n,m,k;
    char a[N],b[N],c[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n>>m>>k;
            cin>>(a+1)>>(b+1);
            sort(a+1,a+n+1);
            sort(b+1,b+m+1);
            int t1=1,t2=1,s1=0,s2=0;
            for(int i=1;t1<=n&&t2<=m;++i)
            {
                if((t1<=n&&s1<k&&a[t1]<b[t2])||s2>=k)
                {
                    ++s1;
                    s2=0;
                    cout<<a[t1++];
                }
                else
                {
                    ++s2;s1=0;
                    cout<<b[t2++];
                }
            }
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
3
2 2 2

*/