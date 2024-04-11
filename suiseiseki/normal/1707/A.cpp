#include <cstdio>
const int Maxn=100000;
int n,q;
int a[Maxn+5];
bool vis[Maxn+5];
void solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cur=0;
	for(int i=n;i>0;i--){
		if(a[i]>cur){
			if(cur<q){
				cur++;
				vis[i]=1;
			}
			else{
				vis[i]=0;
			}
		}
		else{
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",vis[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}