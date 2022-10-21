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

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll g[maxn][3] , l , r;
ll cnt[5];
map<ll , ll> t;

void build_g(ll x , ll y , ll z){
	ll mx = max(x , max(y , z));
	t.clear();
	g[0][1] = g[0][2] = g[0][0] = t[0] = 0;
	for(ll i = 1 ; i < maxn ; i++){
		memset(cnt , 0 , sizeof(cnt));
		ll px = max(0ll , i - x) , py = max(0ll , i - y) , pz = max(0ll , i - z);
		cnt[g[px][0]]++;
		cnt[g[py][1]]++;
		cnt[g[pz][2]]++;
		ll mex = 0;
		while(cnt[mex]) mex++;
		g[i][0] = mex;
		cnt[g[py][1]]--;
		mex = 0;
		while(cnt[mex]) mex++;
		g[i][1] = mex;
		cnt[g[py][1]]++;
		cnt[g[pz][2]]--;
		mex = 0;
		while(cnt[mex]) mex++;
		g[i][2] = mex;
		ll h = 0 , z = 1 , lm = i - mx;
		for(ll j = i ; j > lm ; j--){
			ll r = (j >= 0 ? g[j][0] : 0);
			h += r * z;
			z *= 4;
		}
		for(ll j = i ; j > lm ; j--){
			ll r = (j >= 0 ? g[j][1] : 0);
			h += r * z;
			z *= 3;
		}
		for(ll j = i ; j > lm ; j--){
			ll r = (j >= 0 ? g[j][2] : 0);
			h += r * z;
			z *= 3;
		}
		if(t.count(h)){
			r = i;
			l = t[h];
			break;
		}
		t[h] = i;
	}
	return;
}

ll a[maxn];

ll cal(ll i , ll j){
	if(i < 0) return 0;
	if(i <= r) return g[i][j];
	ll ln = r - l , h = (i - l) % ln + l;
	return g[h][j];
}

void solve(){
	ll n , x , y , z , sum = 0;
	cin>>n>>x>>y>>z;
	build_g(x , y , z);
//	for(ll i = 0 ; i <= 7 ; i++){
//		cout<<g[i][0]<<' ';
//	}
//	cout<<'\n';
//	for(ll i = 0 ; i <= 7 ; i++){
//		cout<<g[i][1]<<' ';
//	}
//	cout<<'\n';
//	for(ll i = 0 ; i <= 7 ; i++){
//		cout<<g[i][2]<<' ';
//	}
//	cout<<'\n';
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		sum ^= cal(a[i] , 0);
	}
//	cout<<sum<<'\n';
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		ll h = sum ^ cal(a[i] , 0);
		ans += (cal(a[i] - x , 0) == h);
		ans += (cal(a[i] - y , 1) == h);
		ans += (cal(a[i] - z , 2) == h);
	}
	cout<<ans<<'\n';
	return;
}

/*
1
2 1 3 4
7 6
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}