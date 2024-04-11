#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

vector<ll> p , adj[MAX_N];
ll dp[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll x , y;
	cin>>x>>y;
	if(y % x != 0){
		cout<<"0\n";
		return 0;
	}
	y /= x;
	if(y == 1){
		cout<<"1\n";
		return 0;
	}
	db sq = sqrt(y);
	for(int i = 2 ; i <= sq ; i++){
		if(y % i == 0){
			p.push_back(i);
			if(i != sq){
				p.push_back(y / i);
			}
		}
	}
	sort(p.begin() , p.end());
	int ps = p.size();
	for(int i = 0 ; i < ps ; i++){
		for(int j = i + 1 ; j < ps ; j++){
			if(p[j] % p[i] == 0){
				adj[j].push_back(i);
			}
		}
	}
	for(int i = 0 ; i < ps ; i++){
		dp[i] = tav(2 , p[i] - 1); dp[i]--;
		for(auto h : adj[i]){
			dp[i] -= dp[h] - md;
			dp[i] %= md;
		}
	}
	ll ans = tav(2 , y - 1) - 1;
	for(int i = 0 ; i < ps ; i++){
		ans -= dp[i] - md;
		ans %= md;
	}
	cout<<ans<<'\n';
	return 0;
}