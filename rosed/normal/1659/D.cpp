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
    int n,r,sum;
    int a[N],c[N],b[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;r=sum=0;
            for(int i=1;i<=n;++i)
            {
                cin>>c[i];
                a[i]=0;
                sum+=c[i];
                b[i]=0;
            }
            int k=sum/n;
            int l=n-k+1;
            b[n+1]=0;
            for(int i=n;i>=1&&k;--i)
            {
                ++b[i];--b[max(0ll,i-k)];
                b[i]+=b[i+1];
                c[i]-=b[i];
                if(c[i]>0)
                {
                    a[i]=1;
                    --k;
                }
                else a[i]=0;
                
            }
            if(k) a[1]=1;
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
7
0 3 4 2 3 2 7



1 1 1 0 0 1

1 1 1 0 0 1
1 1 1 0 0 1
1 1 1 0 0 1
0 1 1 1 0 1
0 0 1 1 1 1
0 0 1 1 1 1

1
6
3 4 6 3 2 6


*/