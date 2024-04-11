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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 5e18;

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

ll c[maxn] , d[maxn] , e[maxn];
vector<pll> a , b;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , k , x , s;
	cin>>n>>m>>k>>x>>s;
	b.push_back({0 , 0});
	for(ll i = 0 ; i < m ; i++){
		cin>>c[i];
	}
	for(ll i = 0 ; i < m ; i++){
		ll h;
		cin>>h;
		a.push_back({h , c[i]});
	}
	for(ll i = 0 ; i < k ; i++){
		cin>>d[i];
	}
	for(ll i = 0 ; i < k ; i++){
		ll h;
		cin>>h;
		b.push_back({h , d[i]});
	}
	sort(all(a));
	e[0] = a[0].second;
	for(ll i = 1 ; i < m ; i++){
		e[i] = min(e[i - 1] , a[i].second);
	}
	a.push_back({inf , inf});
	ll y = 0 , ans = inf;
	for(ll i = k ; i >= 0 ; i--){
		while(a[y].first + b[i].first <= s) y++;
		if(b[i].first > s) continue;
		ll h = 1ll * (y > 0 ? e[y - 1] : x) * (n - b[i].second);
		ans = min(ans , h);
	}
	cout<<ans<<'\n';
	return 0;
}