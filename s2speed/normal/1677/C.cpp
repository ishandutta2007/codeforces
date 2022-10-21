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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , p[maxn] , f[maxn];
bitset<maxn> mark;

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) mark[i] = false;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		p[h] = i;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		f[i] = p[a[i]];
	}
	ll z = 0;
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		ll v = i , cnt = 0;
		while(!mark[v]){
			cnt++;
			mark[v] = true;
			v = f[v];
		}
		z += cnt & 1;
	}
	ll lm = (n / 2) - (z / 2) , ans = 0;
	for(ll i = 0 ; i < lm ; i++) ans -= 2 * i;
	for(ll i = n - lm ; i < n ; i++) ans += 2 * i;
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