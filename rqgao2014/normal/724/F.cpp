#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define sqr(x) ((x)*(x))
#define FF first
#define SS second
#define debug(x) cerr<<#x<<"="<<x<<endl
#define debuge cerr<<"isok"<<endl
using namespace std;

int n,d,mod,inv[15],f[1005],comp[1005][15],dp[1005][15][1005],g[1005][15];

inline void ch(int &x,int y){
	x+=y;
	if(x>=mod) x-=mod;
}

inline int sel(int k,int u){
	if(~comp[k][u]) return comp[k][u];
	int &ans=comp[k][u];ans=1;
	k=f[k];
	for(int i=1;i<=u;i++) ans=(ll)ans*inv[i]%mod;
	for(int i=k+u-1;i>=k;i--) ans=(ll)ans*i%mod;
	return ans;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll) ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}

void solve(int n){
	memset(comp,-1,sizeof(comp));
	f[1]=1;
	dp[1][0][0]=1;
	for(int k=1;k<=n;k+=d){
		int typ=(k-1)/d+1;
		dp[1][0][typ]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=d+1;j++)
			for(int k=1;k<=n;k+=d){
				int typ=(k-1)/d+1;
				for(int u=0;u<=j&&u*k<i;u++)
					ch(dp[i][j][typ],(ll)dp[i-u*k][j-u][typ-1]*sel(k,u)%mod);
			}
		if((i-1)%d==0) f[i]=dp[i][d][(n-1)/d];
	}
}

int main(){
	scanf("%d%d%d",&n,&d,&mod);
	if(n==1){puts("1");return 0;}
	for(int i=1;i<=d;i++) inv[i]=exp(i,mod-2);d--;
	solve(n/2);
	int ans=0;
	if(n%2==0) ch(ans,sel(n/2,2));
	g[1][0]=1;
	for(int i=1;i<=(n-1)/2;i++){
		if((i-1)%d!=0) continue;
		for(int j=n;j>1;j--)
			for(int k=d+1;~k;k--)
				for(int u=1;u<=k&&u*i<=j;u++)
					ch(g[j][k],(ll)g[j-u*i][k-u]*sel(i,u)%mod);
	}
//	debug(g[3][2]);
	ch(ans,g[n][d+1]);
	printf("%d\n",ans);
	return 0;
}