#include <cstdio>
const int Maxn=100000;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	bool flag_0=1,flag_1=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=0){
			flag_0=0;
		}
	}
	if(flag_0){
		puts("0");
		return;
	}
	int l=1,r=n;
	while(l<=n&&a[l]==0){
		l++;
	}
	while(r>0&&a[r]==0){
		r--;
	}
	for(int i=l;i<=r;i++){
		if(a[i]==0){
			flag_1=0;
		}
	}
	if(flag_1){
		puts("1");
		return;
	}
	puts("2");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}