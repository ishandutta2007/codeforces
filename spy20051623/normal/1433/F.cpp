#include <bits/stdc++.h>
using namespace std;

int a[75][75];
int dp[40][75];
int d[75][75];
int x[75],y[75];

int main() {
//	freopen("in.txt", "r", stdin);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&a[i][j]);
		}
	}
	memset(d,-1,sizeof d);
	for(int i=0;i<n;++i){
		memset(dp,-1,sizeof dp);
		dp[0][0]=0;
		for(int j=0;j<m;++j){
			for(int l=m/2-1;l>=0;--l){
				for(int u=0;u<k;++u){
					if(dp[l][u]!=-1)
						dp[l+1][(u+a[i][j])%k]=max(dp[l+1][(u+a[i][j])%k],dp[l][u]+a[i][j]);
				}
			}
		}
		for(int j=0;j<k;++j){
			for(int l=0;l<=m/2;++l){
				d[i][j]=max(d[i][j],dp[l][j]);
			}
		}
	}
	memset(x,-1,sizeof x);
	x[0]=0;
	for(int i=0;i<n;++i){
		memset(y,-1,sizeof y);
		y[0]=0;
		for(int j=0;j<k;++j){
			if(d[i][j]==-1)continue;
			for(int l=0;l<k;++l){
				if(x[l]!=-1)
					y[(j+l)%k]=max(y[(j+l)%k],x[l]+d[i][j]);
			}
		}
		memcpy(x,y,sizeof x);
	}
	printf("%d\n",x[0]);
	return 0;
}