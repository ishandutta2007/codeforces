#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        typedef array<int,2> pr;
        vector<pr> a(n);
        int sum=0;
        for(int i=0;i<n;++i)
        {
            cin>>a[i][0]>>a[i][1];
            sum+=a[i][0];
        }
        sort(a.begin(),a.end(),[&](pr x,pr y){return x[1]-x[0]>y[1]-y[0];});
        vector<int> dp(n+1);
        dp[0]=sum;
        int maxn=dp[0],pos=0;
        for(int i=0;i<n;++i)
        {
            dp[i+1]=dp[i]+a[i][1]-a[i][0];
            if(dp[i+1]>=maxn) maxn=dp[i+1],pos=i+1;
        }
        int m;cin>>m;
        function<int(int&,int&,int,int)> exgcd=[&](int &x,int &y,int a,int b) -> int
        {
            if(!b){x=1,y=0;return a;}
            int g=exgcd(y,x,b,a%b);
            y-=a/b*x;
            return g;
        };
        for(int i=1;i<=m;++i)
        {
            int a,b,x,y;
            cin>>a>>b;
            int g=exgcd(x,y,a,b);
            if(n%g)
            {
                cout<<"-1\n";continue;
            }
            int c=n/g;
            x*=c,y*=c;
            //cout<<x<<' '<<y<<' '<<g<<"!!"<<endl;
            int m1=b/g,m2=a/g;
            y=(y%m2+m2)%m2;
            int t=y*b,m=m2*b;
            if(t>n)
            {
                cout<<"-1\n";
                continue;
            }
            //cout<<t<<' '<<m<<"!!"<<endl;
            //y+km2<=pos
            //km2<=pos-y
            int k=(pos-t)/m;
            //cout<<k<<"!!!!!!!!!!!!!!!"<<endl;
            t+=k*m;
            if(t>n)
            {
                cout<<"-1\n";
                continue;
            }
            int ans=dp[max(0ll,t)];
            t+=m;
            if(t<=n) ans=max(ans,dp[max(0ll,t)]);
            cout<<ans<<'\n';
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
m/i=(-p%i)*inv[i]

inv[i]*i%p=1

*/