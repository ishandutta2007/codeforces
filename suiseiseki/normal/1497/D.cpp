#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=5000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
ll f[Maxn+5],g[Maxn+5];
int n;
int tag[Maxn+5];
int s[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tag[i]);
		g[i]=f[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	ll ans=0;
	for(int i=n;i>0;i--){
		ll val=0;
		for(int j=1;j<=i;j++){
			if(tag[i]!=tag[j]||i==j){
				f[j]=std::max(val+std::abs(s[i]-s[j]),g[i]+std::abs(s[i]-s[j]));
				ans=std::max(ans,f[j]);
				if(tag[i]!=tag[j]){
					val=std::max(val,g[j]+std::abs(s[i]-s[j]));
				}
			}
			else{
				f[j]=-Inf;
			}
		}
		for(int j=1;j<i;j++){
			if(tag[i]!=tag[j]){
				g[j]=std::max(g[j],f[j]);
			}
		}
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