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

ll ds[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

bool merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return (v != u);
}

ll n , m;
ll y[maxn];
vector<pll> ed , sr , t;
vector<ll> v;
ll res[maxn] , cnt[2][maxn];

void que(ll x , ll j){
	t.clear();
	for(ll i = 0 ; i < m ; i++){
		t.push_back({abs(y[i] - x) , (y[i] > x ? -1 : 1) * i});
	}
	sort(all(t));
	iota(ds , ds + n , 0);
	res[j] = 0;
	for(auto p : t){
		ll i = p.second , w = p.first , k;
		if(i < 0) i = -i;
		k = (y[i] <= x);
		ll h = merge(ed[i].first , ed[i].second);
		cnt[k][j] += h;
		res[j] += h * w;
	}
	return;
}

ll ans(ll x){
	ll j = upper_bound(all(v) , x) - v.begin() - 1;
	ll l = x - v[j] , h = res[j] + cnt[1][j] * l - cnt[0][j] * l;
	return h;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , w;
		cin>>v>>u>>w; v--; u--;
		ed.push_back({v , u}); sr.push_back({w , i});
		y[i] = w;
	}
	sort(all(sr));
	v.push_back(0);
	for(ll i = 0 ; i < m ; i++){
		for(ll j = i ; j < m ; j++){
			ll h = (sr[i].first + sr[j].first + 1) / 2;
			v.push_back(h);
		}
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	ll vs = sze(v);
	for(ll j = 0 ; j < vs ; j++){
		que(v[j] , j);
//		cout<<res[j]<<' '<<v[j]<<'\n';
	}
	ll p , q , a , b , c;
	cin>>p>>q>>a>>b>>c;
	ll pr = -1 , hmmm = 0;
	for(ll i = 0 ; i < p ; i++){
		ll h;
		cin>>h;
		hmmm ^= ans(h);
//		cout<<ans(h)<<' ';
		pr = h;
	}
	for(ll i = p ; i < q ; i++){
		pr *= a; pr += b; pr %= c;
		hmmm ^= ans(pr);
//		cout<<ans(pr)<<' ';
	}
//	cout<<'\n';
	cout<<hmmm<<'\n';
	return 0;
}

/*
2 2
1 2 0
1 2 8
1 1 0 0 0
5
*/