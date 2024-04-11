#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int siz(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

const ll MOD = 998244353;

void solve(){
	int n; cin >> n;
	vector<set<int>> v(n);
	vector<int> sz(n,(int)1e9);
	vector<pair<int,int>> g(n);
	for(auto &x : g)cin >> x.first >> x.second;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i == j)continue;
			if(siz(g[i],g[j]) < sz[i]){
				sz[i] = siz(g[i],g[j]);
				v[i].clear();
				v[i].insert(j);
			}
			else if(siz(g[i],g[j]) == sz[i])v[i].insert(j);
		}
	}
	for(int i = 0; i < n; ++i){
		v[i].insert(i);
		if(v[i].size() > 4)v[i].clear();
	}
	for(int i = 0; i < n; ++i){
		bool ok = 1;
		for(auto j : v[i]){
			if(v[i] != v[j]){
				ok = 0;
				break;
			}
		}
		if(!ok)v[i].clear();
		v[i].insert(i);
	}
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i){
		if(*v[i].begin() != i){
			dp[i+1] = dp[i];
			continue;
		}
		for(int j = 0; j <= n-(int)v[i].size(); ++j){
			ll ex = 1;
			for(int k = 0; k < (int)v[i].size(); ++k){
				ex*=n-j-k;
			}
			dp[i+1][j+1]+=dp[i][j]*(n-j);
			dp[i+1][j+1]%=MOD;
			if((int)v[i].size() != 1)dp[i+1][j+(int)v[i].size()]+=dp[i][j]*ex;
			dp[i+1][j+(int)v[i].size()]%=MOD;
		}
	}
	cout << accumulate(dp[n].begin(),dp[n].end(),0ll)%MOD << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	while(t--)solve();
}