#include <cstdio>
typedef long long ll;
const int Maxn=2000;
int n;
ll k;
ll l[Maxn+5],r[Maxn+5],a[Maxn+5];
ll dp[Maxn+5];
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&l[i],&r[i],&a[i]);
	}
	for(int i=n;i>0;i--){
		ll need=a[i]+(i<n&&r[i]==l[i+1]?dp[i+1]:0);
		if((r[i]-l[i]+1)*k<need){
			puts("-1");
			return 0;
		}
		dp[i]=need-1ll*(r[i]-l[i])*k;
		if(dp[i]<0){
			dp[i]=0;
		}
	}
	ll ans=0,cur=k;
	for(int i=1;i<=n;i++){
		if(cur<dp[i]){
			ans+=cur;
			cur=k;
		}
		ans+=a[i];
		cur=((cur-a[i])%k+k)%k;
	}
	printf("%lld\n",ans);
	return 0;
}