#include <cstdio>
const int Maxn=1000;
int n;
int a[Maxn+5];
int lis[Maxn+5],len;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	len=0;
	for(int i=1;i<=n;i++){
		if(len==0||lis[len]+1!=a[i]){
			if(a[i]==1){
				len++;
				lis[len]=1;
			}
			else{
				while(lis[len]+1!=a[i]){
					len--;
				}
				lis[len]++;
			}
		}
		else{
			lis[len]++;
		}
		for(int j=1;j<=len;j++){
			printf("%d%c",lis[j],".\n"[j==len]);
		}
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