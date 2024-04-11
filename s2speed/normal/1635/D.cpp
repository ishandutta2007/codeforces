#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

set<ll> s;
ll dp[maxn];
vector<ll> v;

bool check(ll r){
	while(r){
		if(s.count(r)) return false;
		ll h = r & 1;
		if(h == 1){
			r >>= 1;
			continue;
		}
		h = r & 3;
		if(h == 0){
			r >>= 2;
			continue;
		}
		break;
	}
	return true;
}	

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	ll n , p;
	cin>>n>>p;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
	}
	sort(all(v));
	for(auto h : v){
		if(check(h)){
			s.insert(h);
			for(ll j = 1 ; j < 60 ; j++){
				if(h < (1 << j)){
					dp[j]++;
					break;
				}
			}
		}
	}
	ll ans = 0;
	for(ll i = 1 ; i <= p ; i++){
		dp[i] %= md;
		ans += dp[i];
		dp[i + 1] += dp[i];
		dp[i + 2] += dp[i];
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}