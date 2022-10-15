#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<20;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++) if(a[j]&(1<<i)) cnt++;
        for(int j=1;j<=cnt;j++) b[j]|=(1<<i);
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=1LL*b[i]*b[i];
    printf("%lld\n",ans);
    return 0;
}