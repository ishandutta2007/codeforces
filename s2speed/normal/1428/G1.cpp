#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn] , pd[maxn] , f[maxn] , w[7];
deque<pll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , -31 , sizeof(dp));
	dp[0] = 0;
	ll k;
	cin>>k; k *= 3;
	for(ll i = 0 ; i < 6 ; i++){
		cin>>w[i];
	}
	for(ll t = 0 , r = 1 ; t < 6 ; t++ , r *= 10){
		ll x = r * 3;
		for(ll i = 0 ; i < maxn ; i++){
			pd[i] = dp[i] - w[t] * (i / x);
		}
		for(ll j = 0 ; j < x ; j++){
			v.clear();
			for(ll i = j ; i < maxn ; i += x){
				ll h = i - 1ll * (k + 1) * x;
				while(sze(v)){
					pll p = v.back();
					if(p.first > pd[i]) break;
					v.pop_back();
				}
				v.push_back({pd[i] , i});
				if(v.front().second == h) v.pop_front();
				f[i] = v.front().first + w[t] * (i / x);
			}
		}
		for(ll i = 0 ; i < maxn ; i++){
			pd[i] = dp[i] - w[t] * ((i + r) / x);
		}
		for(ll j = 0 ; j < x ; j++){
			v.clear();
			for(ll i = j + r ; i < maxn ; i += x){
				ll z = i - r , h = z - 1ll * (k - 2) * x;
				while(sze(v)){
					pll p = v.back();
					if(p.first > pd[z]) break;
					v.pop_back();
				}
				v.push_back({pd[z] , z});
				if(v.front().second == h) v.pop_front();
				f[i] = max(f[i] , v.front().first + w[t] * (i / x));
			}
		}
		for(ll i = 0 ; i < maxn ; i++){
			pd[i] = dp[i] - w[t] * ((i + 2 * r) / x);
		}
		for(ll j = 0 ; j < x ; j++){
			v.clear();
			for(ll i = j + 2 * r ; i < maxn ; i += x){
				ll z = i - 2 * r , h = z - 1ll * (k - 2) * x;
				while(sze(v)){
					pll p = v.back();
					if(p.first > pd[z]) break;
					v.pop_back();
				}
				v.push_back({pd[z] , z});
				if(v.front().second == h) v.pop_front();
				f[i] = max(f[i] , v.front().first + w[t] * (i / x));
			}
		}
		for(ll i = 0 ; i < maxn ; i++){
			ll h = i - k * x + 5 * r , e = i - k * x - r , o = (k - 3) * w[t];
			while(h > -1 && h > e){
				f[i] = max(f[i] , dp[h] + o);
				h -= r;
			}
		}
		memcpy(dp , f , sizeof(f));
	}
	ll q;
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		ll x;
		cin>>x;
		cout<<dp[x]<<'\n';
	}
	return 0;
}

/*
1
1 2 3 4 5 6
4
6
26
526
1526
*/