#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int inf=1e9;
int t,n; char s[N];
int a[N],b[N],dp[N][2][4];
void upd(int &x,int y){
	x=min(x,y);
}
int solve(int mask){
	b[1]=mask>>0&1;
	b[2]=mask>>1&1;
	b[3]=mask>>2&1;
	int cost=0;
	for(int i=1;i<=3;i++)if(a[i]!=b[i])cost++;
	for(int i=4;i<=n;i++)b[i]=a[i];
	for(int i=0;i<=n;i++)for(int j=0;j<2;j++)for(int k=0;k<4;k++)dp[i][j][k]=inf;
	if(b[3]==1){
		int cnt=0;
		for(int i=3;i>=1;i--){
			if(b[i]==1)cnt++;
			else break;
		}
		dp[3][1][cnt] = 0;
	}
	if(b[3]==0){
		int cnt=0;
		for(int i=3;i>=1;i--){
			if(b[i]==0)cnt++;
			else break;
		}
		dp[3][0][cnt] = 0;
	}

	for(int i=3;i<n;i++){
		for(int j=0;j<2;j++){
			for(int x=0;x<3;x++){
				if(dp[i][j][x]<inf){
					//printf("dp[%d][%d][%d] = %d\n", i,j,x,dp[i][j][x]);
				}
				if(x<2)
					upd(dp[i+1][j][x+1],dp[i][j][x] + (b[i+1]==j?0:1) );
				upd(dp[i+1][j^1][1], dp[i][j][x] + (b[i+1]==j?1:0));
			}
		}
	}	
	int tmp=inf;
	for(int j=0;j<2;j++){
		for(int k=1;k<=2;k++){
			if(j!=b[1]){
				tmp=min(tmp,dp[n][j][k]);
			}else{
				int cnt=0;
				for(int c=1;c<=3;c++){
					if(b[c]==b[1])cnt++;
					else break;
				}
				if(cnt+k<=2) tmp=min(tmp,dp[n][j][k]);
			}	
		}
	}
	return tmp+cost;
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++){
			a[i]=(s[i]=='L'?0:1);
		}
		//solve(1); return 0;
		int ans=inf;
		for(int i=1;i<7;i++)ans=min(ans,solve(i));
		cout<<ans<<endl;
	}	
}