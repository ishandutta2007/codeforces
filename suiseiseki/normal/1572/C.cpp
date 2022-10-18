#include <cstdio>
#include <algorithm>
const int Maxn=3000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
int f[Maxn+5][Maxn+5];
int nxt[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	n=std::unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;i++){
		nxt[i]=-1;
		for(int j=i;j<=n;j++){
			f[i][j]=Inf;
		}
		f[i][i]=0;
	}
	for(int l=n;l>0;l--){
		for(int r=l+1;r<=n;r++){
			if(a[r]==a[l]&&nxt[l]==-1){
				nxt[l]=r;
			}
			f[l][r]=f[l+1][r];
			for(int i=nxt[l];i!=-1&&i<=r;i=nxt[i]){
				f[l][r]=std::max(f[l][r],f[l+1][i-1]+f[i][r]+1);
			}
		}
	}
	printf("%d\n",n-1-f[1][n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}