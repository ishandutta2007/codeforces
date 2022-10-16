#include <cstdio>
int n,k;
void solve(){
	scanf("%d%d",&n,&k);
	int sum=k;
	sum-=n;
	sum=(sum%k+k)%k;
	if(sum==0){
		puts("1");
		return;
	}
	int ans=(sum-1)/n+1;
	printf("%d\n",ans+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}