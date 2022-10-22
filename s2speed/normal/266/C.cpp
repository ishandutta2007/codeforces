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

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll cnt[maxn] , p[maxn] , a[maxn];
vector<ll> adj[maxn] , r , c , t;
vector<pll> v;
bitset<maxn> mark;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 1 ; i < n ; i++){
		ll x , y;
		cin>>x>>y; x--; y--;
		cnt[x]++;
		adj[x].push_back(y);
	}
	for(ll i = 0 ; i < n ; i++){
		v.push_back({cnt[i] , i});
	}
	sort(all(v));
	for(ll i = 0 ; i < n ; i++){
		r.push_back(v[i].second);
		for(auto j : adj[v[i].second]){
			if(mark[j]) continue;
			c.push_back(j);
			mark[j] = true;
		}
	}
	v.clear();
	iota(p , p + n , 0);
	iota(a , a + n , 0);
	for(ll i = 0 ; i < n ; i++){
		if(i == p[r[i]]) continue;
		v.push_back({i , p[r[i]]});
		t.push_back(1);
		swap(a[i] , a[p[r[i]]]);
		p[a[p[r[i]]]] = p[r[i]];
	}
	iota(p , p + n , 0);
	iota(a , a + n , 0);
	ll cs = sze(c);
	for(ll i = 0 ; i < cs ; i++){
		if(i == p[c[i]]) continue;
		v.push_back({i , p[c[i]]});
		t.push_back(2);
		swap(a[i] , a[p[c[i]]]);
		p[a[p[c[i]]]] = p[c[i]];
	}
	ll vs = sze(v);
	cout<<vs<<'\n';
	for(ll i = 0 ; i < vs ; i++){
		cout<<t[i]<<' '<<v[i].first + 1<<' '<<v[i].second + 1<<'\n';
	}
	return 0;
}