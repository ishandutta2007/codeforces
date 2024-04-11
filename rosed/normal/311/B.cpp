#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e5+10,mod=998244353,inf=2e9;
    int n,m,k;
    int d[N];
    int a[N],s[N];
    int q[N];
    int dp[N][110];
    inline int y(int x,int k){return dp[x][k-1]+s[x];}
    inline int x(int x){return x;}
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m>>k;
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<=k;++i) dp[0][i]=0;
        for(int i=2;i<=n;++i)
        {
            cin>>d[i];
            d[i]+=d[i-1];
        }
        for(int i=1;i<=m;++i)
        {
            int h,t;cin>>h>>t;
            a[i]=t-d[h];
        }
        sort(a+1,a+m+1);
        for(int i=1;i<=m;++i) s[i]=s[i-1]+a[i];
        //dp[r][j]=dp[l][j-1]+(r-l)*a[r]-(s[r]-s[l])
        //dp[r][j]=dp[l][j-1]+r*a[r]-l*a[r]-s[r]+s[l];
        //dp[l][j-1]+s[l]=l*a[r]+dp[r][j]-r*a[r]+s[r];
        for(int j=1;j<=k;++j)
        {
            int head=0,tail=0;
            q[0]=0;
            for(int r=1;r<=m;++r)
            {
                while(head<tail&&y(q[head+1],j)-y(q[head],j)<=a[r]*(x(q[head+1])-x(q[head]))) ++head;
                int l=q[head];//cout<<l<<"-----------------"<<endl;
                dp[r][j]=dp[l][j-1]+(r-l)*a[r]-(s[r]-s[l]);
                //cout<<dp[r][j]<<' '<<r<<' '<<j<<"!!"<<endl;
                while(head<tail&&(y(r,j)-y(q[tail],j))*(x(q[tail])-x(q[tail-1]))<=(y(q[tail],j)-y(q[tail-1],j))*(x(r)-x(q[tail]))) --tail;
                q[++tail]=r;
            }
        }
        int ans=inf*inf;
        for(int j=1;j<=k;++j) ans=min(ans,dp[m][j]);
        cout<<ans<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
1
1 2 3 4

*/