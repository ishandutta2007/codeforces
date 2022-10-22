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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll ds[maxn] , dsz[maxn] , dsl[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	dsz[v] += dsz[u];
	dsl[v] += dsl[u];
	ds[u] = v;
	return;
}

ll n , lm[maxn] , sum = 0;
vector<plll> ed;

bool check(ll x){
	for(ll i = 0 ; i < n ; i++){
		ds[i] = i;
		dsz[i] = 1;
		dsl[i] = lm[i];
	}
	for(auto q : ed){
		pll p = q.second;
		ll v = p.first , u = p.second , w = q.first;
		if(w >= x) break;
		merge(v , u);
	}
	for(ll i = 0 ; i < n ; i++){
		if(sum - dsl[i] < dsz[i]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		ed.push_back({w , {v , u}});
	}
	sort(all(ed));
	for(ll i = 0 ; i < n ; i++){
		cin>>lm[i]; sum += lm[i];
	}
	ll l = 0 , r = 1e4 + 16;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			l = m;
		} else {
			r = m;
		}
	}
	cout<<l<<'\n';
	return 0;
}