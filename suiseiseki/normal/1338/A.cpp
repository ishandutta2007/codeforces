#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	int max_val=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		max_val=std::max(max_val,-(a[i]-a[i-1]));
		a[i]=std::max(a[i],a[i-1]);
	}
	if(max_val==0){
		puts("0");
		return;
	}
	int ans=32-__builtin_clz(max_val);
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