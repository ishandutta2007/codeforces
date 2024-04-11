#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll n,c,a[MAXN],b[MAXN],deq[MAXN],dp[MAXN];
int main()
{
    scanf("%I64d%I64d",&n,&c);
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        sum+=a[i];
    }
    if(n<c)
    {
    	printf("%I64d\n",sum);
    	return 0;
    }
    memset(deq,0,sizeof(deq));
    memset(dp,0,sizeof(dp));
    ll s=0,t=0;
	for(ll i=0;i<n;i++)
	{
		while(s<t&&a[deq[t-1]]>=a[i]) t--;
		deq[t++]=i;
		if(i-c+1>=0)
		{
			b[i-c+1]=a[deq[s]];
			if(deq[s]==i-c+1) s++;
		}
	}
	for(ll i=n-c;i>=0;i--)
		dp[i]=max(dp[i+1],b[i]+dp[i+c]);
	printf("%I64d\n",sum-dp[0]);
    return 0;
}