#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],v[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&v[i]);
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            if(i>=n-k+1&&v[i]!=0&&v[i]!=-1) ans=0;
            if(i<=k) ans=1LL*ans*i%MOD;
            else if(v[i-k]==-1) ans=1LL*ans*i%MOD;
            else if(!v[i-k]) ans=1LL*ans*min(i,k+1)%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}