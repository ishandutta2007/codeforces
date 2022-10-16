#include <cstdio>
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
typedef long long ll;
const int Maxn=100;
int n,k;
int p[Maxn+5];
ll sum[Maxn+5];
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		sum[i]=sum[i-1]+p[i];
	}
	ll ans=0;
	for(int i=n;i>1;i--){
		ll tmp_s=(100ll*p[i]-1)/k+1;
		ans=max(ans,tmp_s-sum[i-1]);
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