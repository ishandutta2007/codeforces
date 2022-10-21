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

const ll maxn = 3e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> f[maxn];
ll a[maxn * maxn] , cnt[maxn * maxn] , x[maxn * maxn];
vector<ll> v;
vector<pll> b[maxn * maxn];

void solve(){
	ll n , m;
	cin>>n>>m;
	ll lm = n * m;
	v.clear();
	for(ll i = 0 ; i < lm ; i++){
		cnt[i] = x[i] = 0;
		b[i].clear();
		f[i / m][i % m] = false;
	}
	for(ll i = 0 ; i < lm ; i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < lm ; i++){
		a[i] = lower_bound(all(v) , a[i]) - v.begin();
		cnt[a[i]]++;
	}
	ll cur = 0;
	for(ll i = 0 ; i < lm ; i++){
		while(cnt[i]){
			b[i].push_back({cur / m , -(cur % m)});
			cnt[i]--;
			cur++;
		}
		sort(all(b[i]));
	}
	ll ans = 0;
	for(ll i = 0 ; i < lm ; i++){
		ll y = b[a[i]][x[a[i]]].first , z = -b[a[i]][x[a[i]]++].second;
		for(ll j = 0 ; j < z ; j++){
			ans += f[y][j];
		}
		f[y][z] = true;
//		cout<<y<<' '<<z<<'\n';
	}
	cout<<ans<<'\n';
	return;
}

/*
1
3 3
3 4 4 1 1 1 1 1 2
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}