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
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            int num1=0,num2=0;
            bool flag=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(i>1)
                {
                    if(a[i]-a[i-1]<=1) continue;
                    if(a[i]-a[i-1]<=2) ++num1;
                    else if(a[i]-a[i-1]<=3) ++num2;
                    else flag=1;
                }
            }
            if(flag||num2>=2||num1+num2>=3||(num1&&num2)) cout<<"NO\n";
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
5
3
1 3 5
3
1 2 3
4
1 2 3 7
1
1000000
3
2 5 6

*/