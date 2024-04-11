#include <cstdio>
const int Maxn=50;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans^=(a[i]-1)&1;
	}
	if(ans==0){
		puts("maomao90");
	}
	else{
		puts("errorgorn");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}