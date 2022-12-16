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
    int n=12,m;
    int f[(1<<12)+10][12][12][13];
    int s[13][12][12];
    int dp[13][23][12][12];
    int inv[55];
    //S,t1t2i
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
    inline int all(int n)
    {
        return (1LL<<n)-1;
    }
    inline void add(int &x,int y)
    {
        x=(x+y>=mod)?(x+y-mod):(x+y);
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        inv[0]=inv[1]=1;
        for(int i=2;i<=22;++i) inv[i]=fast(i,mod-2);
        for(n=2;n<=12;++n)
        {
            for(int s=0;s<=all(n);++s)
                for(int j=0;j<=11;++j)
                    for(int k=0;k<=11;++k)
                        for(int l=0;l<=n;++l)
                            f[s][j][k][l]=0;
            f[0][0][0][0]=1;
            for(int o=1;o<=n;++o)
            {
                for(int s=0;s<=all(n);++s)
                for(int c1=0;c1<=11;++c1)
                for(int c2=0;c2<=11;++c2)
                for(int lst=0;lst<=n;++lst)
                if(f[s][c1][c2][lst]&&__builtin_popcount(s)+1==o)
                {
                    int mx=0;
                    for(int i=1;i<=n;++i)
                        if((s>>(i-1))&1) mx=i;
                    for(int j=1;j<=n;++j) if(!((s>>(j-1))&1))
                    {
                        if(max(mx,j)>o||o==n)
                        {
                            int t1=c1+__builtin_popcount(s&(all(n)-all(j)));
                            int t2=c2+(lst>j);
                            if(t1<=11&&t2<=11) add(f[s|(1<<(j-1))][t1][t2][j],f[s][c1][c2][lst]);
                        }
                    }
                }
            }
            for(int i=1;i<=11;++i)
                for(int j=1;j<=11;++j)
                    for(int k=1;k<=n;++k)
                        add(s[n][i][j],f[all(n)][i][j][k]);
        }
        dp[0][0][0][0]=1;
        for(int a=0;a<=11;++a)
            for(int b=0;b<=22;++b)
                for(int c=0;c<=11;++c)
                    for(int d=0;d<=11;++d)
                        if(dp[a][b][c][d])
                            for(n=2;n<=12;++n)
                                for(int i=1;c+i<=11;++i)
                                    for(int j=1;d+j<=11;++j)
                                        add(dp[a+1][b+n][c+i][d+j],dp[a][b][c][d]*s[n][i][j]%mod);
        int T;cin>>T;  
        while(T--)
        {
            int x,y,z;cin>>x>>y>>z;
            int ans=0;
            for(int i=2;i<=min(22ll,x);++i)
            {
                int tmp=x-i+1;
                for(int j=1;j<=11;++j)
                {
                    add(ans,dp[j][i][y][z]*tmp%mod);
                    tmp=tmp*(x-i+j+1)%mod*inv[j+1]%mod;
                    //cout<<(x-i+j+1)<<"!!"<<endl;

                }
                //x-i,j
                //x1+x2+x3+x_{j+1}=x-i+(j+1)
                //C(x-i+(j+1)-1,j)
            }
            cout<<ans<<'\n';
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
1 2 3 4

*/