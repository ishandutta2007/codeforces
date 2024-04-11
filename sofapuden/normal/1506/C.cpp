#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int fin(int l1, int r1, int l2, int r2, vector<vector<vector<vector<int>>>> &dp, string &a, string &b){
	if(r1 == 0)return r2;
	if(r2 == 0)return r1;
	if(dp[l1][r1-1][l2][r2-1])return dp[l1][r1-1][l2][r2-1];
	if(a.substr(l1,r1) == b.substr(l2,r2)){
		return 0;
	}
	return dp[l1][r1-1][l2][r2-1] = min({fin(l1,r1-1,l2,r2,dp,a,b),fin(l1+1,r1-1,l2,r2,dp,a,b),fin(l1,r1,l2,r2-1,dp,a,b),fin(l1,r1,l2+1,r2-1,dp,a,b)})+1;
}
int main(){
	ll t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		int n = a.size(), m = b.size();
		vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>> (n, vector<vector<int>> (m, vector<int> (m,0))));
		cout << fin(0,n,0,m,dp,a,b) << "\n";

	}
}