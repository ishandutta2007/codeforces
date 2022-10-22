#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 4e5 + 16 , md = 1e9 + 7 , inf = 2e17;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
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

ll a[maxn] , cnt[maxn];
vector<ll> v , p;
vector<vector<ll>> b;
vector<pll> u , w;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < n ; i++){
		a[i] = lower_bound(all(v) , a[i]) - v.begin();
		cnt[a[i]]++;
	}
	for(ll i = 0 ; i < n ; i++){
		p.push_back(cnt[i]);
	}
	sort(all(p)); p.push_back(inf);
	ll cur = 0 , x = 0 , ans = 0 , k;
	for(ll i = 1 ; i <= n ; i++){
		while(p[x] == i - 1) x++;
		cur += n - x;
		ll h = i * (cur / i);
		if(h < i * i) break;
		if(ans < h){
			ans = h;
			k = i;
		}
	}
	cout<<ans<<'\n';
	cout<<k<<' '<<ans / k<<'\n';
	ll m = ans / k;
	b.resize(k);
	for(ll i = 0 ; i < k ; i++) b[i].resize(m);
	for(ll i = 0 ; i < k ; i++){
		for(ll j = 0 ; j < m ; j++){
			ll h = j - i;
			if(h < 0) h += m;
			u.push_back({h , i});
		}
	}
	sort(all(u));
	for(ll i = 0 ; i < n ; i++){
		w.push_back({min(cnt[i] , k) , i});
	}
	sort(all(w) , greater<pll>());
	x = 0;
	for(ll i = 0 ; i < n ; i++){
		ll t = w[i].first , s = w[i].second , lm = min(x + t , ans);
		for(ll e = x ; e < lm ; e++){
			ll i = u[e].second , j;
			j = i + u[e].first; if(j >= m) j -= m;
			b[i][j] = s;
		}
		x += t;
		if(x > lm) break;
	}
	for(ll i = 0 ; i < k ; i++){
		for(ll j = 0 ; j < m ; j++){
			cout<<v[b[i][j]]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}