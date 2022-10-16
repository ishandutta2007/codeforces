#include <cstdio>
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){
		puts("0");
	}
	else if(n==1||m==1){
		puts("1");
	}
	else{
		puts("2");
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