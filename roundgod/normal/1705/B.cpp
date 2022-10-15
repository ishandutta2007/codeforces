#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ll ans=0;
        bool has=false;
        for(int i=1;i<=n-1;i++)
        {
            ans+=a[i];
            if(!a[i]&&has) ans++;
            if(a[i]) has=true;
        }
        printf("%lld\n",ans);
    }
    return 0;
}