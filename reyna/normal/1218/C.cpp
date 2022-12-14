#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int K=5e5+1;
int n,m,k;
vector<int>tr;
int x[K],y[K],d[K],t[K];
ll e[K];
ll dp[501][501];
ll c[501][501];
vector<int>v[501][501],h[501][501];
ll vc[501][501],hc[501][501];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=k ;i++){
		cin >> x[i] >> y[i] >> d[i] >> t[i] >> e[i];
		int z=0;
		if((x[i]+y[i])%4==(t[i]+0)%4 && x[i]+y[i]>=t[i]+0) z|=1;
		if((x[i]+y[i])%4==(t[i]+1)%4 && x[i]+y[i]>=t[i]+1) z|=2;
		if((x[i]+y[i]+d[i])%4==(t[i]+2)%4 && x[i]+y[i]+d[i]>=t[i]+2) z|=4;
		if((x[i]+y[i]+d[i])%4==(t[i]+3)%4 && x[i]+y[i]+d[i]>=t[i]+3) z|=8;
		if(z==(z&-z) || z==10){
			if(z&1) c[x[i]][y[i]]+=e[i];
			if(z&2) c[x[i]+d[i]][y[i]-d[i]]+=e[i];
			if(z&4) c[x[i]+d[i]][y[i]]+=e[i];
			if(z&8) c[x[i]][y[i]+d[i]]+=e[i];
		}
		else{
			if(z&1) c[x[i]][y[i]]+=e[i];
			if(z&2) c[x[i]+d[i]][y[i]-d[i]]+=e[i];
			if(z==5) h[x[i]+d[i]][y[i]].push_back(i);
			else if(z==9) v[x[i]][y[i]+d[i]].push_back(i);
			else v[x[i]+d[i]][y[i]].push_back(i);
		}
	}
	for(int i=0; i<n ;i++){
		for(int j=0; j<m ;j++){
			if(i==0 && j==0){
				dp[0][0]=c[0][0];continue;
			}
			for(auto cur:v[i][j]){
				c[i][j]+=e[cur];
				vc[i][j-d[cur]+1]-=e[cur];
			}
			for(auto cur:h[i][j]){
				c[i][j]+=e[cur];
				hc[i-d[cur]+1][j]-=e[cur];
			}
			//cout << "duy" << endl;
			dp[i][j]=1e18;
			ll sum=c[i][j]+hc[i][j];
			for(int x=i-1; x>=0 ;x--){
				dp[i][j]=min(dp[i][j],dp[x][j]+sum);
				sum+=c[x][j]+hc[x][j];
			}
			sum=c[i][j]+vc[i][j];
			for(int y=j-1; y>=0 ;y--){
				dp[i][j]=min(dp[i][j],dp[i][y]+sum);
				sum+=c[i][y]+vc[i][y];
			}
			//cout << dp[i][j] << ' ';
		}
	}
	cout << dp[n-1][m-1] << '\n';
}