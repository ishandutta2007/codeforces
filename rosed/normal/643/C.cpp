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
    const int N=200000+10,mod=1e9+7,inv2=5e8+4,inf=1e18;
    const double pi=acos(-1.0);
    int n,m;
    double t[N],s[N];
    double st[N],t1[N];
    double dp[N][51];
    int q[N];
    int head,tail;
    double y(int i,int k)
    {
        return dp[i][k]-st[i]+s[i]*t1[i];
    }
    double x(int i)
    {
        return s[i];
    }
    double slope(int i,int j,int id)
    {
        if(x(i)==x(j))
            return y(i,id)>y(j,id)?inf:-inf;
        return (y(i,id)-y(j,id))/(x(i)-x(j));
    }
    int fcmp(double x,double y)
    {
        return fabs(x-y)<=eps?0:x>y?1:-1;
    }
    void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        //(s[i]-s[j-1])/t[i]

        //dp[i][k]=dp[j][k-1]+st[i]-st[j]-s[j]*(t1[i]-t1[j])

        //dp[j][k-1]-st[j]+s[j]*t1[j]=s[j]*t1[i]+dp[i][k]-st[i]

        //st[i]s[j]

        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            cin>>t[i];
            s[i]=s[i-1]+t[i];
            st[i]=st[i-1]+1.0*s[i]/t[i];
            t1[i]=t1[i-1]+1.0/t[i];
        }
        for(int i=0;i<=n;++i)
            for(int j=0;j<=m;++j) dp[i][j]=1e18;
        dp[0][0]=0;
        for(int k=1;k<=m;++k)
        {
            head=1,tail=0;
            q[++tail]=0;
            for(int i=1;i<=n;++i)
            {
                while(head<tail&& fcmp(slope(q[head+1],q[head],k-1),t1[i] ) <= 0 ) ++head;
                int j=q[head];
                dp[i][k]=dp[j][k-1]+st[i]-st[j]-s[j]*(t1[i]-t1[j]);
                while(head<tail&& fcmp(slope(i,q[tail-1],k-1),slope(q[tail],q[tail-1],k-1)) <= 0 ) --tail;
                q[++tail]=i;
            }
        }
        cout<<fixed<<setprecision(10)<<dp[n][m]<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
20 4
25 66 10 18 67 40 66 49 3 51 61 29 10 72 71 22 63 4 74 67

*/