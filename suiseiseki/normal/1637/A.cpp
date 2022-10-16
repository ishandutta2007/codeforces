#include <cstdio>
const int Maxn=10000;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	bool flag=1;
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			flag=0;
			break;
		}
	}
	if(flag){
		puts("NO");
	}
	else{
		puts("YES");
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