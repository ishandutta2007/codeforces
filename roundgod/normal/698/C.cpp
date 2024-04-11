#include<bits/stdc++.h>
#define MAXN 20
#define MAXM (1<<20)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
double p[MAXN],dp[MAXM];
double ans[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&p[i]);
        if(p[i]>1e-6) cnt++;
    }
    k=min(k,cnt);
    dp[0]=1;
    for(int i=0;i<(1<<n);i++)
    {
        if(__builtin_popcount(i)>=k) continue;
        double sum=0.0;
        for(int j=0;j<n;j++) if(!(i&(1<<j))) sum+=p[j];
        for(int j=0;j<n;j++)
            if(!(i&(1<<j)))
                dp[i^(1<<j)]+=dp[i]*p[j]/sum;
    }
    for(int i=0;i<(1<<n);i++)
    {
        if(__builtin_popcount(i)!=k) continue;
        for(int j=0;j<n;j++) if(i&(1<<j)) ans[j]+=dp[i];
    }
    for(int i=0;i<n;i++) printf("%.10f ",ans[i]);
    return 0;
}