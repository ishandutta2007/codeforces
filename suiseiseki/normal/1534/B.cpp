#include <cstdio>
#include <algorithm>
const int Maxn=400000;
typedef long long ll;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	a[0]=a[n+1]=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			ans+=a[i]-std::max(a[i-1],a[i+1]);
			a[i]=std::max(a[i-1],a[i+1]);
		}
	}
	for(int i=1;i<=n+1;i++){
		ans+=std::abs(a[i]-a[i-1]);
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