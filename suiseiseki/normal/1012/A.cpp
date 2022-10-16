#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int n;
int a[Maxn*2+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);i++){
		scanf("%d",&a[i]);
	}
	std::sort(a+1,a+1+(n<<1));
	ll ans=1ll*(a[n]-a[1])*(a[n<<1]-a[n+1]);
	for(int i=2;i<=n;i++){
		ans=std::min(ans,1ll*(a[i+n-1]-a[i])*(a[n<<1]-a[1]));
	}
	printf("%lld\n",ans);
}
int main(){
	solve();
	return 0;
}