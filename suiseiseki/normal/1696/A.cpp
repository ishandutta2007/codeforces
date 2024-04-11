#include <cstdio>
#include <algorithm>
const int Maxn=2000;
int n,z;
int a[Maxn+5];
int ans;
void solve(){
	scanf("%d%d",&n,&z);
	ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans=std::max(ans,a[i]|z);
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