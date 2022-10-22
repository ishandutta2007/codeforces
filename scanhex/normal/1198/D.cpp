#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=55;
int n;
string matr[N];
int dp[N][N][N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>matr[i];
	}
	for(int len1=1;len1<=n;++len1)
		for(int len2=1;len2<=n;++len2){
			for(int i=0;i+len1<=n;++i)
				for(int j=0;j+len2<=n;++j){
					int i1=i+len1;
					int j1=j+len2;
					dp[i][j][i1][j1]=max(i1-i,j1-j);
					if(len1==1&&len2==1&&matr[i][j]=='.'){
						dp[i][j][i1][j1]=0;
					}
					for(int i2=i+1;i2<i1;++i2){
						dp[i][j][i1][j1]=min(dp[i][j][i1][j1],dp[i][j][i2][j1]+dp[i2][j][i1][j1]);
					}
					for(int j2=j+1;j2<j1;++j2){
						dp[i][j][i1][j1]=min(dp[i][j][i1][j1],dp[i][j][i1][j2]+dp[i][j2][i1][j1]);
					}
				}
		}
	cout<<dp[0][0][n][n];
	return 0;
}