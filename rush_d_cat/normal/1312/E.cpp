#include <bits/stdc++.h>
using namespace std;
const int N=502;
int n,a[N];
int f[N][N],g[N][N];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=1e9;
	}
	for(int i=1;i<=n;i++){
		f[i][i]=1; g[i][i]=a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			// [i,j]
			for(int k=i;k<j;k++){
				if(g[i][k]&&g[k+1][j]&&(g[i][k]==g[k+1][j])){
					g[i][j]=g[i][k]+1;
				}
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			// [i,j]
			if(g[i][j]) f[i][j]=1;
			for(int k=i;k<j;k++){
				f[i][j]=min(f[i][k]+f[k+1][j],f[i][j]);
			}
		}
	}
	cout<<f[1][n]<<endl;
}