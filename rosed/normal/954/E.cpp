#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-10)
    const int N=1e6+10,mod=1e9+7,inf=2e9;
    int n,m;
    double ans;
    struct node
    {
        int a,t;
    }a[N],b[N];
    inline bool cmp1(node a,node b)
    {
        return a.t<b.t;
    }
    inline bool cmp2(node a,node b)
    {
        return a.t>b.t;
    }
    inline int fcmp(double a,double b)
    {
        if(fabs(a-b)<eps) return 0;
        if(a>b) return 1;
        return -1;
    }
    inline bool check(double sum)
    {
        
        double s1=0,t1=0,s2=0,t2=0;
        for(int i=1;i<=n&&fcmp(s1,sum)==-1;++i)
        {
            double x=min((double)b[i].a,sum-s1);
            s1+=x;
            t1+=x*b[i].t;
        }
        for(int i=1;i<=n&&fcmp(s2,sum)==-1;++i)
        {
            double x=min((double)a[i].a,sum-s2);
            s2+=x;
            t2+=x*a[i].t;
        }
        double r1=(double)t1/s1,r2=(double)t2/s2;
       // cout<<sum<<' '<<r1<<' '<<r2<<"!!"<<endl;
        if(fcmp(r1,m)>=0&&fcmp(r2,m)<=0) return 1;
        return 0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        double l=0,r=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i].a;
            r+=a[i].a;
            b[i].a=a[i].a;
        }
        for(int i=1;i<=n;++i)
        {
            cin>>a[i].t;
            b[i].t=a[i].t;
        }
        sort(a+1,a+n+1,cmp1);
        sort(b+1,b+n+1,cmp2);
        while(r-l>1e-8)
        {
            double mid=(l+r)/2.0;
            if(check(mid)) l=mid;
            else r=mid;
        }
        cout<<fixed<<setprecision(8)<<l<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*




*/