#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
ll sump[MAXN],sumn[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
    {
        sump[i]=sump[i-1]; sumn[i]=sumn[i-1];
        if(a[i]>=a[i-1]) sump[i]+=(a[i]-a[i-1]); else sumn[i]+=(a[i-1]-a[i]);
    }
    for(int i=0;i<m;i++)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        if(s<t) printf("%lld\n",sumn[t]-sumn[s]);
        else printf("%lld\n",sump[s]-sump[t]);
    }
    return 0;
}