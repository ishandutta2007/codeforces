#include<bits/stdc++.h>
#define MAXN 600005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll a[MAXN],b[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
        for(int i=n+1;i<=2*n;i++) a[i]=a[i-n],b[i]=b[i-n];
        ll ans=INF;
        ll s=a[1];
        for(int i=2;i<=n;i++) s+=max(0LL,a[i]-b[i-1]);
        ans=s;
        for(int i=n+1;i<=2*n-1;i++)
        {
            s-=a[i-n];
            s+=max(0LL,a[i]-b[i-1]);
            s-=max(0LL,a[i+1-n]-b[i-n]);
            s+=a[i+1-n];
            ans=min(ans,s);
        }
        printf("%lld\n",ans);
    }
    return 0;
}