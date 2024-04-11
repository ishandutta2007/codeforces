#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2e5 + 20;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

vector<ll> g , ans;

void g_build(){
	g.push_back(2);
	ll h = 4;
	for(int i = 1 ; h < 1e18 ; i++ , h *= 2){
		ll q = g[i - 1] + h;
		g.push_back(q);
	}
	return;
}

void solve(){
	ll n;
	cin>>n;
	ans.clear();
	if(n % 2){
		cout<<"-1\n";
		return;
	}
	ans.push_back(1);
	n -= 2;
	ll gs = g.size();
	for(int i = gs - 1 ; i >= 0 ; i--){
		while(n >= g[i]){
			n -= g[i];
			for(int j = 0 ; j < i ; j++){
				ans.push_back(0);
			}
			ans.push_back(1);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i : ans){
		cout<<i<<' ';
	}
	cout<<'\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	g_build();
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}