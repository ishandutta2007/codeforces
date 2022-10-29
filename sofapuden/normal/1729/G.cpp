#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e9+7;

vector<int> pos;
vector<pair<ll,ll>> dp;

string s, t;

int N;

pair<ll,ll> f(int n){
	if(n >= N)return {0,1};
	if(dp[n] != make_pair(-1ll,-1ll))return dp[n];
	pair<ll,ll> ans = {M, M};
	for(int i = n; i < N; ++i){
		if(pos[i]-pos[n] >= t.size())break;
		pair<ll,ll> cu;
		bool fo = 0;
		for(int j = i+1; j < N; ++j){
			if(pos[j]-pos[i] >= t.size()){
				fo = 1;
				cu = f(j);
				break;
			}
		}
		if(!fo){
			cu = f(N);
		}
		if(cu.first < ans.first)ans = cu;
		else if(cu.first == ans.first)ans.second+=cu.second;
	}
	ans.second%=M;
	ans.first++;
	return dp[n] = ans;
}

void solve(){
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	pos.clear();
	for(int i = 0; i < n - m + 1; ++i){
		if(t == s.substr(i,m))pos.push_back(i);
	}
	N = pos.size();
	dp.clear();
	dp.resize(N,{-1,-1});
	cout << f(0).first << ' ' << f(0).second << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}