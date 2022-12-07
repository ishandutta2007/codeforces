#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n,m,a[100];
long double dp[60][60][60],f[100][100],ans=0,me[60][60][60];

long double v(int n,int k,int m){
	if (me[n][k][m]!=-1)return me[n][k][m];
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for (int i=0;i<n;i++)for (int j=0;j<=i;j++){
		f[i+1][j+1]+=f[i][j]/m;
		f[i+1][j]+=f[i][j]*(m-1)/m;
	}
	me[n][k][m]=f[n][k];
	return f[n][k];

}

int main(){
	cin >> n >> m;
	cout.precision(10);
	for (int i=0;i<m;i++)cin >> a[i];
	memset(dp,0,sizeof(dp));
	for (int i=0;i<55;i++)for (int j=0;j<55;j++)for (int k=0;k<55;k++)me[i][j][k]=-1;
	dp[0][0][0]=1;
	for (int i=0;i<m;i++)for (int j=0;j<=n;j++)for (int k=0;k<55;k++)if (dp[i][j][k]>0){
		for (int l=0;l<=n-j;l++){
			int o=l/a[i]+(l%a[i]>0);
			dp[i+1][j+l][max(k,o)]+=dp[i][j][k]*v(n-j,l,m-i);
		}
		
	}
	for (int i=0;i<=n;i++)ans+=i*dp[m][n][i];
	cout << fixed << ans << endl;
	return 0;
}