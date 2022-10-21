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

ll ans[maxn];
vector<ll> v;

void solve(){
	v.clear();
	ll n , k;
	cin>>n>>k; k--;
	if(n < 62){
		if((1ll << (n - 1)) <= k){
			cout<<"-1\n";
			return;
		}
	}
	v.push_back(0);
	ll lm = min(60ll , n - 1);
	for(ll j = 0 ; j < lm ; j++){
		v.push_back(k & (1ll << j));
	}
	reverse(all(v));
	lm = max(0ll , n - 61);
	for(ll i = 0 ; i < lm ; i++){
		ans[i] = i;
	}
	ll vs = sze(v);
	ll pr = lm - 1 , cnt = 1 , x = lm;
	for(ll i = 0 ; i < vs ; i++){
		if(!v[i]){
			ll h = pr + cnt , o = h;
			cnt = 0;
			while(h > pr){
				ans[x++] = h--;
			}
			pr = o;
		}
		cnt++;
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i] + 1<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}