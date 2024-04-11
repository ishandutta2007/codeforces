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

const ll maxn = 3e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , nx[maxn] , pr[maxn];
set<ll> s;
vector<pll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		v.push_back({a[i] , i});
	}
	s.insert(0); s.insert(n + 1);
	nx[0] = n + 1; pr[n + 1] = 0;
	sort(all(v) , greater<pll>());
	db ans = 0;
	for(ll e = 0 ; e < n ; e++){
		ll i = v[e].second;
		auto it = s.lower_bound(i);
		ll nxt = *it , prv;
		it--; prv = *it;
		nx[prv] = i; pr[nxt] = i;
		nx[i] = nxt; pr[i] = prv;
		s.insert(i);
		ll ls , v = i , cnt = 0;
		db hl = 0 , hr = 0 , z = 1;
		while(v != 0 && cnt < 60){
			ls = v;
			v = pr[v];
			hl += (ls - v) * z;
			z /= 2;
			cnt++;
		}
		v = i; z = 1; cnt = 0;
		while(v != n + 1 && cnt < 60){
			ls = v;
			v = nx[v];
			hr += (v - ls) * z;
			z /= 2;
			cnt++;
		}
		ans += hl * hr * a[i];
	}
	ans /= (db)2 * n * n;
	cout<<fixed<<setprecision(10)<<ans<<'\n';
	return 0;
}