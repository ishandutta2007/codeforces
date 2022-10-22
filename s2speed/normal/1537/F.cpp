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

const ll maxn = 1e6 + 16 , p = 131 , md = 2000000357 , inf = 2e16;

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

ll a[maxn] , b[maxn];
vector<ll> dsu[maxn];
ll ds[maxn];
bitset<maxn> s;

bool merge(ll v , ll u){
	if(ds[v] == ds[u]){
		return (s[v] == s[u]);
	}
	bool c = !(s[v] ^ s[u]);
	v = ds[v]; u = ds[u];
	if(sze(dsu[v]) < sze(dsu[u])) swap(v , u);
	for(auto i : dsu[u]){
		s[i] = s[i] ^ c;
		ds[i] = v;
		dsu[v].push_back(i);
	}
	dsu[u].clear();
	return false;
}

void solve(){
	ll n , m , sum = 0;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		sum += h - a[i];
		b[i] = h;
	}
	for(ll i = 0 ; i < n ; i++){
		ds[i] = i;
		dsu[i].clear();
		dsu[i].push_back(i);
		s[i] = false;
	}
	bool res = false;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		res |= merge(v , u);
	}
	if(sum < 0) sum = -sum;
	if(sum & 1){
		cout<<"NO\n";
		return;
	}
	if(res){
		cout<<"YES\n";
		return;
	}
	ll cnt[] = {0 , 0};
	for(ll i = 0 ; i < n ; i++){
		cnt[s[i]] += a[i] - b[i];
	}
	cout<<(cnt[0] == cnt[1] ? "YES\n" : "NO\n");
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}