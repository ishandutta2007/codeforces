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
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        if(m>n*n)
        {
            cout<<"-1\n";
            return;
        }
        vector a(n+1,vector<int>(n+1));
        for(int i=1;i<=n;++i)
        {
            for(int j=i;j<=n;++j)
            {
                if(i==j)
                {
                    if(m>=1)
                    {
                        a[i][j]=1;
                        --m;
                    }
                    else break;
                }
                else
                {
                    if(m>=2)
                    {
                        a[i][j]=a[j][i]=1;
                        m-=2;
                    }
                    else break;
                }
            }
        }
        if(m!=0)
        {
            cout<<"-1\n";
            return;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                cout<<a[i][j]<<" \n"[j==n];
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/