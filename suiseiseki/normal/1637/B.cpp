#include <cstdio>
const int Maxn=100;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			ans+=r-l+1;
			for(int i=l;i<=r;i++){
				ans+=(a[i]==0);
			}
		}
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