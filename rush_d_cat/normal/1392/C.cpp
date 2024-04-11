#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n;
int a[N],pre[N],d[N];
LL dp[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)pre[i]=max(pre[i-1],a[i]);
		for(int i=1;i<=n;i++)d[i]=pre[i]-a[i];
		dp[n]=d[n];
		for(int i=n-1;i>=1;i--){
			if(a[i]>=a[i+1])dp[i]=dp[i+1];
			else dp[i]=dp[i+1]+d[i]-d[i+1];
		}
		printf("%lld\n", dp[1]);
	}
}