#include <cstdio>
void solve(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("9");
	}
	else{
		printf("98");
		int pos=9;
		for(int i=3;i<=n;i++){
			printf("%d",pos);
			pos++;
			if(pos>=10){
				pos-=10;
			}
		}
		puts("");
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