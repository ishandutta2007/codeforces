#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e5+10,inf=2e9,mod=998244353;
    int n,m;
    int a[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            int sum=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            for(int i=1;i<n;++i)
            {
                if(a[i]) sum+=a[i];
                else
                {
                    if(!sum) continue;
                    ++sum;
                }
            }
            cout<<sum<<'\n';
        }
        
    }
}
signed main()
{
    red::main();
    return 0;
}
/*


a a b

t=b-a;

3 4 5
3 3 4
2 3 3
2 2 2

2 4 4

*/