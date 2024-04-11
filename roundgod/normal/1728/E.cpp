#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define int long long
#define S second
using namespace std;
typedef pair<int,int> P;
int n,m,a[MAXN];
int sum[MAXN];
int all=0,ans;
int extgcd(int a,int b,int &x,int &y)
{
    int d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
int mod_inverse(int a,int m)
{
    int x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        all+=y; a[i]=x-y;
    }
    sort(a+1,a+n+1,greater<long long>());
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int last=n;
    for(int i=1;i<=n;i++) if(a[i]<0) {last=i-1; break;}
    scanf("%lld",&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        int g=__gcd(x,y);
        if(n%g) {puts("-1"); continue;}
        int gx=x/g,gy=y/g;
        int need=mod_inverse(gx%gy,gy)*((n%y)/g)%gy;
        assert(need<y/__gcd(x,y));
        if(1LL*need*x>n) {puts("-1"); continue;}
        int addon=y/__gcd(x,y);
        int more=max(0LL,(last-need*x)/(addon*x));
        //printf("need=%lld\n",need);
        need+=more*addon;
        //printf("need=%lld\n",need);
        ans=-INF;
        if(1LL*need*x<=n) ans=max(ans,all+sum[need*x]);
        if(1LL*(need+addon)*x<=n) ans=max(ans,all+sum[(need+addon)*x]);
        if(need>=addon&&1LL*(need-addon)*x<=n) ans=max(ans,all+sum[(need-addon)*x]);
        if(ans==-INF) puts("-1"); else printf("%lld\n",ans);
    }
    return 0;
}