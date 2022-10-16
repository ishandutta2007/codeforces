#include <cstdio>
const int Maxn=200000;
int n;
int a[Maxn+5];
bool check(int x){
	static int b[Maxn+5];
	int len=0;
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			continue;
		}
		b[++len]=a[i];
	}
	int l=1,r=len;
	while(l<r){
		if(b[l]==b[r]){
			l++,r--;
		}
		else{
			break;
		}
	}
	return l>=r;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			l++,r--;
		}
		else{
			break;
		}
	}
	if(l>=r){
		puts("YES");
		return;
	}
	if(check(a[l])){
		puts("YES");
	}
	else if(check(a[r])){
		puts("YES");
	}
	else{
		puts("NO");
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