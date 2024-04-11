#include <cstdio>
const int Maxn=100000;
int n;
int b[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%1d",&b[i]);
	}
	int last=-1;
	for(int i=1;i<=n;i++){
		if(b[i]+1!=last){
			putchar('1');
			last=b[i]+1;
		}
		else{
			putchar('0');
			last=b[i];
		}
	}
	putchar('\n');
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}