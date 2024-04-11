#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
int prea[MAXN],preb[MAXN],nxta[MAXN],nxtb[MAXN];
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    ll ans=1LL*n*(n-1)/2;
    nxta[n+1]=nxtb[n+1]=n+1;
    prea[0]=preb[0]=0;
    for(int i=n;i>=1;i--)
    {
        nxta[i]=nxta[i+1]; if(str[i]=='A') nxta[i]=i;
        nxtb[i]=nxtb[i+1]; if(str[i]=='B') nxtb[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        prea[i]=prea[i-1]; if(str[i]=='A') prea[i]=i;
        preb[i]=preb[i-1]; if(str[i]=='B') preb[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='A') ans-=nxta[i+1]-i-1;
        else ans-=nxtb[i+1]-i-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='A') ans-=i-prea[i-1]-1;
        else ans-=i-preb[i-1]-1;
    }
    for(int i=2;i<=n;i++) if(str[i]!=str[i-1]) ans++;
    printf("%lld\n",ans);
    return 0;
}