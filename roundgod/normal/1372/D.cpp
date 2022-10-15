#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll preodd[MAXN],sufodd[MAXN],preeven[MAXN],sufeven[MAXN];
ll s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    preodd[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(i&1) preodd[i]=preodd[i-2]+a[i];
        else preeven[i]=preeven[i-2]+a[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(i&1) sufodd[i]=sufodd[i+2]+a[i];
        else sufeven[i]=sufeven[i+2]+a[i];
    }
    ll ans=sufodd[1];
    for(int i=1;i<=n;i++)
    {
        if(i&1) ans=max(ans,preodd[i]+sufeven[i+1]);
        else ans=max(ans,preeven[i]+sufodd[i+1]);
    }
    printf("%lld\n",ans);
    return 0;
}