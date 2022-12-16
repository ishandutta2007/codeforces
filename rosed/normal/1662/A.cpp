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
    int n;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            for(int i=1;i<=10;++i) a[i]=0;
            for(int i=1;i<=n;++i)
            {
                int x,y;cin>>x>>y;
                a[y]=max(a[y],x);
            }
            bool flag=0;
            int sum=0;
            for(int i=1;i<=10;++i)
            {
                if(a[i]==0) flag=1;
                sum+=a[i];
            }
            if(flag) cout<<"MOREPROBLEMS\n";
            else cout<<sum<<'\n';
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
5
1 2
2 3
3 4
3 5

*/