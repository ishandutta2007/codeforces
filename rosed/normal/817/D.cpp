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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        vector<int> a(n+1);
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        vector<int> b(n+1);
        function<void(int,int)> solve=[&](int l,int r) -> void
        {
            if(l==r) return;
            solve(l,mid);
            solve(mid+1,r);
            //max min
            // 
            int maxn,minn,minn1,minn2,maxn1,maxn2,t1,t2,sum;


            maxn=-inf,minn=inf,t2=mid+1;
            for(int i=mid;i>=l;--i)
            {
                maxn=max(maxn,a[i]);
                minn=min(minn,a[i]);
                while(t2<=r&&minn<=a[t2]&&a[t2]<=maxn) ++t2;
                ans+=(t2-(mid+1))*(maxn-minn);
            }
            
            //maxmin
            // 
            maxn=-inf,t1=mid,t2=mid+1;
            minn1=inf,minn2=inf;

            sum=0;
            b[mid]=inf;
            for(int i=mid+1;i<=r;++i) b[i]=min(b[i-1],a[i]);
            for(int i=mid;i>=l;--i)
            {
                maxn=max(maxn,a[i]);
                minn1=min(minn1,a[i]);
                while(t1<=r&&minn1<=minn2)
                {
                    if(t1+1<=r) minn2=min(minn2,a[t1+1]);
                    if(t1!=mid) sum-=b[t1];
                    ++t1;
                }
                while(t2<=r&&a[t2]<maxn) sum+=b[t2],++t2;
                if(t2>t1) ans+=(t2-t1)*maxn-sum;
            }

            //min max
            // 
            minn=inf,t1=mid,t2=mid+1;
            maxn1=-inf,maxn2=-inf;
            sum=0;
            b[mid]=-inf;
            for(int i=mid+1;i<=r;++i) b[i]=max(b[i-1],a[i]);
            for(int i=mid;i>=l;--i)
            {
                minn=min(minn,a[i]);
                maxn1=max(maxn1,a[i]);
                while(t1<=r&&maxn1>=maxn2)
                {
                    if(t1+1<=r) maxn2=max(maxn2,a[t1+1]);
                    if(t1!=mid) sum-=b[t1];
                    ++t1;
                }
                while(t2<=r&&a[t2]>minn) sum+=b[t2],++t2;
                if(t2>t1) ans+=sum-(t2-t1)*minn;
            }

            //max min
            // 
            t1=mid;
            minn=inf,maxn=-inf;
            for(int i=mid+1;i<=r;++i)
            {
                minn=min(minn,a[i]);
                maxn=max(maxn,a[i]);
                while(t1>=l&&minn<=a[t1]&&a[t1]<maxn) --t1;
                ans+=(mid-t1)*(maxn-minn);
            }

            t1=mid;
            minn=inf,maxn=-inf;
            for(int i=mid+1;i<=r;++i)
            {
                minn=min(minn,a[i]);
                maxn=max(maxn,a[i]);
                while(t1>=l&&minn<a[t1]&&a[t1]<=maxn) --t1;
                ans+=(mid-t1)*(maxn-minn);
            }

            t1=mid;
            minn=inf,maxn=-inf;
            for(int i=mid+1;i<=r;++i)
            {
                minn=min(minn,a[i]);
                maxn=max(maxn,a[i]);
                while(t1>=l&&minn<a[t1]&&a[t1]<maxn) --t1;
                ans-=(mid-t1)*(maxn-minn);
            }

        };
        solve(1,n);
        cout<<ans<<'\n';
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