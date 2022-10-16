#include <cstdio>
#include <algorithm>
const int Maxn=15;
typedef long long ll;
int n;
int a[Maxn+5];
void solve(){
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	for(int i=1;i<=n;i++){
		ll tmp=a[i];
		ll sum=0;
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			ll cur=a[j];
			while(cur%2==0){
				cur/=2;
				tmp*=2;
			}
			sum+=cur;
		}
		sum+=tmp;
		ans=std::max(ans,sum);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}