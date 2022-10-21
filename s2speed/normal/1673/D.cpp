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

vector<ll> v;

void solve(){
	ll b , q , y , c , r , z;
	cin>>b>>q>>y>>c>>r>>z;
	if(r % q != 0){
		cout<<"0\n";
		return;
	}
	ll h = b % q , o = c % q;
	h += (h < 0) * q; o += (o < 0) * q;
	if(h != o){
		cout<<"0\n";
		return;
	}
	ll b2 , c2;
	b2 = (y - 1) * q + b; c2 = (z - 1) * r + c;
	if(c < b || c2 > b2){
		cout<<"0\n";
		return;
	}
	if(c2 + r > b2 || c - r < b){
		cout<<"-1\n";
		return;
	}
	v.clear();
	ll sq = sqrt(r);
	for(ll i = 1 ; i <= sq ; i++){
		if(r % i == 0){
			v.push_back(i);
			if(i * i != r){
				v.push_back(r / i);
			}
		}
	}
	ll ans = 0;
	for(auto i : v){
		if(lcm(i , q) != r) continue;
		ll h = (r / i); h = h * h % md;
		ans += h;
	}
	ans %= md;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}