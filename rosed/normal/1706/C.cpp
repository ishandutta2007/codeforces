#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=998244353;
    int n,m;
    int a[N];
    int pre[N],suf[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            int sum1=0,sum2=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
            }
            if(n%2==1)
            {
                for(int i=2;i<n;i+=2)
                {
                    sum1+=max(0ll,max(a[i-1],a[i+1])+1-a[i]);
                }
                cout<<sum1<<'\n';
            }
            else
            {
                suf[n]=suf[n+1]=suf[n+2]=0;
                pre[0]=pre[1]=pre[2]=0;
                for(int i=2;i<n;i+=2)
                {
                    pre[i]=pre[i-2]+max(0ll,max(a[i-1],a[i+1])+1-a[i]);
                }
                for(int i=n-1;i>1;i-=2)
                {
                    suf[i]=suf[i+2]+max(0ll,max(a[i-1],a[i+1])+1-a[i]);
                }
                int sum=0x3f3f3f3f3f3f3f3f;
                for(int i=0;i<n;i+=2) sum=min(sum,pre[i]+suf[i+3]);
                cout<<sum<<'\n';
            }
            
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