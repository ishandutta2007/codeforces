#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

void solve(){
	int n, s; cin >> n >> s;
	vector<pair<ll,ll>> AB(n); 
	for(auto &x : AB)cin >> x.first;
	for(auto &x : AB)cin >> x.second;
	sort(AB.begin(),AB.end());
	map<ll,ll> M;
	for(int i = 0; i < s; ++i){
		M[AB[i].second]++;
	}
	ll ans = 1;
	for(int i = 1; i <= n; ++i){
		if(i+s <= n)M[AB[i+s-1].second]++;
		if(M[i]){
			M[i]--;
			continue;
		}
		else{
			ans*=M[-1];
			ans%=MOD;
			M[-1]--;
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}