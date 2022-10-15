#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k[MAXN],c[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&k[i]);
        for(int i=1;i<=m;i++) scanf("%d",&c[i]);
        sort(k+1,k+n+1);
        int l=0;
        while(l<min(n,m)&&k[n-l]>=l+1) l++;
        ll ans=0;
        for(int i=1;i<=l;i++) ans+=c[i];
        for(int i=1;i<=n-l;i++) ans+=c[k[i]];
        printf("%lld\n",ans);
    }    
    return 0;
}