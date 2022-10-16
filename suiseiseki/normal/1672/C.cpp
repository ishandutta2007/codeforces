#include <cstdio>
const int Maxn=200000;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int pos_l=0,pos_r=0;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			pos_l=i;
			break;
		}
	}
	if(pos_l==0){
		puts("0");
		return;
	}
	for(int i=n;i>1;i--){
		if(a[i]==a[i-1]){
			pos_r=i;
			break;
		}
	}
	if(pos_l+1==pos_r){
		puts("0");
		return;
	}
	if(pos_l+2==pos_r){
		puts("1");
		return;
	}
	printf("%d\n",pos_r-pos_l-2);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}