#include <cstdio>
const int Maxn=400000;
const int Mod=1000000007;
int n;
int a[Maxn+5],b[Maxn+5];
int p[Maxn+5];
bool vis[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[a[i]]=i;
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		for(int j=i;!vis[j];j=p[b[j]]){
			vis[j]=1;
		}
		ans=(ans<<1)%Mod;
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