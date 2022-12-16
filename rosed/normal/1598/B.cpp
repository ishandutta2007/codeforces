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
    const int N=1e6+10,mod=998244353,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector a(n+1,vector<int>(6));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=5;++j)
            {
                cin>>a[i][j];
            }
        }
        for(int k=1;k<=5;++k)
        {
            for(int j=k+1;j<=5;++j)
            {
                int sum1=0,sum2=0,sum=0;
                for(int i=1;i<=n;++i)
                {
                    sum1+=a[i][k];
                    sum2+=a[i][j];
                    sum+=(a[i][k]|a[i][j]);
                }
                if(sum==n&&sum1>=n/2&&sum2>=n/2)
                {
                    cout<<"YES\n";
                    return;
                }
            }
        }
        cout<<"NO\n";
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
1 7 5 6 8 2 6 5

0 8 5 6 8 0 8 5
3
5 6 5
3 8 5
2
3
8
*/