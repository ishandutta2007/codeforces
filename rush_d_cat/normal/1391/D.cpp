#include <bits/stdc++.h>
using namespace std;
const int N=1000000 + 10;
int n, m;
int a[N],tot;
int dp[N][9];
bool ok[9][9];
int dis[9][9];


int main() {
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			int x=i^j,c=0;
			for(int k=0;k<3;k++)if(x>>k&1)c++;
			dis[i][j]=c;
		}
	}
	scanf("%d%d",&n,&m);

	char s[n+2][m+2];
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	if (min(n,m) >= 4) {
		return !printf("-1\n");
	}
	if (min(n,m) == 1) {
		return !printf("0\n");
	}
	if(min(n,m)==2){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				int c1=(i>>0&1)+(i>>1&1)+(j>>0&1)+(j>>1&1);
				if(c1%2==1)ok[i][j]=1;
			}
		}
	}
	if(min(n,m)==3){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				int c1=(i>>0&1)+(i>>1&1)+(j>>0&1)+(j>>1&1);
				int c2=(i>>1&1)+(i>>2&1)+(j>>1&1)+(j>>2&1);
				if(c1%2==1 && c2%2==1) {
					//printf("ok %d %d\n", i,j);
					ok[i][j]=1;
				}
			}
		}
	}

	if(n<=m){
		for(int j=1;j<=m;j++){
			int mask=0;
			for(int i=1;i<=n;i++){
				if(s[i][j]=='1')mask|=(1<<(i-1));
			}
			a[++tot]=mask;
		}
	} else {
		for(int i=1;i<=n;i++){
			int mask=0;
			for(int j=1;j<=m;j++){
				if(s[i][j]=='1')mask|=(1<<(j-1));
			}
			a[++tot]=mask;
		}
	}
	for(int i=0;i<N;i++)for(int j=0;j<8;j++)dp[i][j]=1e9;
	int k=min(n,m);
	for(int i=0;i<1<<k;i++) dp[1][i]=dis[i][a[1]];
	for(int i=2;i<=tot;i++){
		for(int j=0;j<1<<k;j++){
			for(int x=0;x<1<<k;x++){
				if(ok[x][j]){
					dp[i][j]=min(dp[i][j], dp[i-1][x]+dis[j][a[i]]);
				}
			}
		}
	}

	int ans=1e9;
	for(int i=0;i<1<<k;i++)ans=min(ans,dp[tot][i]);
	if(ans<=n*m) printf("%d\n", ans);
	else printf("-1\n");
}