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

const ll maxn = 4e4 + 17 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll lcm(ll a , ll b){
	return 1ll * a * b / gcd(a , b);
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

ll a[40][40];
pll b[maxn];
set<ll> s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll z = 1 << 9 , o = 16;
	for(ll k = 0 ; k < 5 ; k++){
		ll i = o , cnt = 0 , lm = o << 1;
		while(i < 32){
			for(ll j = 0 ; j < 32 ; j++){
				a[i][j] += z;
			}
			i++;
			cnt++;
			if(cnt == lm){
				cnt = 0;
				i += lm;
			}
		}
		z >>= 2; o >>= 1;
	}
	z = 1 << 8; o = 16;
	for(ll k = 0 ; k < 5 ; k++){
		ll j = o , cnt = 0 , lm = o << 1;
		while(j < 32){
			for(ll i = 0 ; i < 32 ; i++){
				a[i][j] += z;
			}
			j++;
			cnt++;
			if(cnt == lm){
				cnt = 0;
				j += lm;
			}
		}
		z >>= 2; o >>= 1;
	}
	for(ll i = 0 ; i < 32 ; i++){
		for(ll j = 0 ; j < 32 ; j++){
			b[a[i][j]] = {i , j};
		}
	}
//	ll res = 0;
//	for(ll i = 0 ; i < 32 ; i++){
//		for(ll j = 0 ; j < 32 ; j++){
//			if(i){
//				res += a[i][j] ^ a[i - 1][j];
//			} else {
//				res += a[i][j] ^ a[i][j - 1];
//			}
//			s.insert(a[i][j]);
//		}
//	}
//	cout<<res<<'\n';
//	auto it = s.end(); it--;
//	cout<<*(s.begin())<<' '<<*it<<'\n';
	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n - 1 ; j++){
			ll h = a[i][j] ^ a[i][j + 1];
			cout<<h<<' ';
		}
		cout<<endl;
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		for(ll j = 0 ; j < n ; j++){
			ll h = a[i][j] ^ a[i + 1][j];
			cout<<h<<' ';
		}
		cout<<endl;
	}
	ll pr = 0;
	for(ll e = 0 ; e < q ; e++){
		ll h , res;
		cin>>h;
		res = h ^ pr;
		pr = res;
		cout<<b[res].first + 1<<' '<<b[res].second + 1<<endl;
	}
	return 0;
}