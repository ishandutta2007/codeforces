#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> tr;
vector<ll> s;

pair<ll,ll> f(int x, int k){
	if(!tr[x].size())return {s[x]*k,s[x]*(k+1)};
	ll path = k / tr[x].size();
	pair<ll,ll> ans = {s[x]*k,s[x]*(k+1)};
	vector<ll> ex;
	for(auto y : tr[x]){
		pair<ll,ll> z = f(y,path);
		ans.first+=z.first;
		ans.second+=z.first;
		ex.push_back(z.second-z.first);
	}
	sort(ex.rbegin(),ex.rend());
	for(int i = 0; i < (k%(int)tr[x].size()); ++i){
		ans.first+=ex[i];
		ans.second+=ex[i];
	}
	ans.second+=ex[k%(int)tr[x].size()];
	return ans;
}

void solve(){
	int n, k; cin >> n >> k;
	tr.clear();
	s.clear();
	tr.resize(n);
	s.resize(n);
	for(int i = 1; i < n; ++i){
		int x; cin >> x;
		tr[x-1].push_back(i);
	}
	for(auto &x : s)cin >> x;
	cout << f(0,k).first << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();
}