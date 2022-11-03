#include <bits/stdc++.h>
using namespace std;

int n,h,m;
int dp[55][55][55];
int l[55],r[55],x[55],c[55];
int tmp[55];

int main(){
	scanf("%d%d%d",&n,&h,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",l+i,r+i,x+i,c+i);
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				memset(tmp,0,sizeof(tmp));
				for(int f=1;f<=m;f++){
					if(l[f]<=k&&k<=r[f]&&i<=l[f]&&r[f]<=j){
						tmp[x[f]+1]+=c[f];
					}
				}
				for(int f=1;f<=h;f++){
					tmp[f]+=tmp[f-1];
				}
				for(int f=0;f<=h;f++){
					dp[i][j][f]=max(dp[i][j][f],dp[i][k-1][f]+dp[k+1][j][f]-tmp[f]+f*f);
					if(f){
						dp[i][j][f]=max(dp[i][j][f],dp[i][j][f-1]);
					}
				}
			}
		}
	}
	printf("%d\n",dp[1][n][h]);
	return 0;
}