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
    int n,m,q,k;
    struct node
    {
        int x,y;
    }a[N];
    bool vis1[N],vis2[N];
    int sum1,sum2,sum;
    inline int fast(int x,int k)
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m>>k>>q;
            sum1=sum2=sum=0;
            for(int i=1;i<=n;++i) vis1[i]=0;
            for(int i=1;i<=m;++i) vis2[i]=0;
            for(int i=1;i<=q;++i)
            {
                cin>>a[i].x>>a[i].y;
            }
            for(int i=q;i;--i)
            {
                int x=a[i].x,y=a[i].y;
                bool b1=0,b2=0;
                if(!vis1[x]&&sum2!=m)
                {
                    vis1[x]=1;b1=1;
                }
                if(!vis2[y]&&sum1!=n)
                {
                    vis2[y]=1;b2=1;
                }
                //cout<<b1<<' '<<b2<<"!!"<<endl;
                if(b1) ++sum1;
                if(b2) ++sum2;
                if(b1|b2) ++sum;
            }
            cout<<fast(k,sum)<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}