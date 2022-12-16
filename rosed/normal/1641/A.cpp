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
    int n,k,sum;
    int a[N];
    map<int,int> q;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>k;q.clear();sum=0;
            for(int i=1;i<=n;++i) {cin>>a[i];++q[a[i]];}
            sort(a+1,a+n+1);
            n=unique(a+1,a+n+1)-a-1;
            for(int i=1;i<=n;++i)
            {
                int x=a[i];
                while(q[x]>0)
                {
                    if(q[x*k]>0) --q[x*k];
                    else ++sum;
                    --q[x];
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

*/