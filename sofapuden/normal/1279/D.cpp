#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 998244353;

ll pw(ll a, ll b){
	a%=M;
	ll ret = 1;
	while(b){
		if(b&1)ret = ret * a % M;
		a = a * a % M;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x){
	return pw(x,M-2);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	map<int,int> Ma;
	vector<vector<int>> g(n);
	for(auto &x : g){
		int z; cin >> z;
		x.resize(z);
		for(auto &y : x){
			cin >> y;
			Ma[y]++;
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ll cu = 0;
		for(auto y : g[i])cu+=Ma[y];
		ans+=cu*inv(1ll*n*n*g[i].size())%M;
	}
	cout << ans%M << '\n';
}