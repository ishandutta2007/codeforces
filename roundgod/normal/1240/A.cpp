#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n,p[MAXN],x,a,y,b;
ll sum[MAXN];
ll k;
bool check(int xx)
{
    ll l=1LL*a*b/__gcd(a,b);
    int cnt1=xx/a,cnt2=xx/b,cnt3=xx/l;
    cnt1-=cnt3; cnt2-=cnt3;
    ll res=1LL*sum[cnt3]*(x+y)+1LL*(sum[cnt1+cnt3]-sum[cnt3])*x+1LL*(sum[cnt1+cnt2+cnt3]-sum[cnt1+cnt3])*y;
    return res>=k;
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) sum[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
            p[i]/=100;
        }
        sort(p+1,p+n+1,greater<int>());
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+p[i];
        scanf("%d%d%d%d",&x,&a,&y,&b);
        if(x<y)
        {
            swap(x,y);
            swap(a,b);
        }
        scanf("%lld",&k);
        int l=0,r=n+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) r=mid; else l=mid;
        }
        if(r==n+1) puts("-1"); else printf("%d\n",r);
    }
    return 0;
}