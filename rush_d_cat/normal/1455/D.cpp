#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
const int inf=1e9+7;

int t,n,x,a[N];
int f[N][N][N];
void upd(int &x,int y){
	x=min(x,y);
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++) f[i][j][k]=inf;
		f[0][0][0]=0;
		a[0]=x;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					if(f[i][j][k]<1e8){
						//printf("f[%d][%d][%d]=%d\n", i,j,k,f[i][j][k]);
					}
					if(a[i+1]>=a[j]||(j==0 && i==0)){
						//printf("f[%d][%d][%d] -> (%d,%d,%d)\n", i,j,k,i+1,i+1,k);
						upd(f[i+1][i+1][k],f[i][j][k]);
					}
					//set
					if(a[i+1]>a[k] && a[k]>=a[j]){
						upd(f[i+1][k][i+1],f[i][j][k]+1);
					}
				}
			}
		}
		int ans=inf;
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)upd(ans,f[n][i][j]);
		printf("%d\n", ans==inf?-1:ans);
	}	
}