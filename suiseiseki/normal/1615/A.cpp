#include <cstdio>
const int Maxn=100;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%n==0){
		puts("0");
	}
	else{
		puts("1");
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