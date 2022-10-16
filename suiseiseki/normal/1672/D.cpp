#include <cstdio>
const int Maxn=200000;
int n;
int a[Maxn+5],b[Maxn+5];
int num[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		num[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=n,j=n;i>0;i--){
		while(a[j]!=b[i]){
			if(num[a[j]]==0){
				puts("NO");
				return;
			}
			num[a[j]]--;
			j--;
		}
		while(i>0&&a[j]==b[i-1]){
			num[a[j]]++;
			i--;
		}
		j--;
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}