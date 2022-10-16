#include <cstdio>
const int Maxn=1000000;
const int Mod=998244353;
int n,k;
int v[Maxn+5];
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=n-k+1;i<=n;i++){
		if(v[i]>0){
			puts("0");
			return;
		}
	}
	int ans=1;
	for(int i=n-k;i>0;i--){
		if(v[i]==0){
			ans=1ll*ans*(k+1)%Mod;
		}
		else if(v[i]==-1){
			ans=1ll*ans*(i+k)%Mod;
		}
	}
	for(int i=1;i<=k;i++){
		ans=1ll*ans*i%Mod;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}