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

const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> dsu[maxn];

void merge(ll v , ll u){
	if(v == u) return;
	if(sze(dsu[v]) > sze(dsu[u])){
		dsu[v].swap(dsu[u]);
	}
	for(auto i : dsu[v]){
		dsu[u].push_back(i);
	}
	dsu[v].clear();
	return;
}

ll ans[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll q , n = 0;
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		ll t;
		cin>>t;
		if(t == 1){
			ll x;
			cin>>x;
			dsu[x].push_back(n);
			n++;
		} else {
			ll x , y;
			cin>>x>>y;
			merge(x , y);
		}
	}
	for(ll i = 1 ; i < maxn ; i++){
		for(auto j : dsu[i]){
			ans[j] = i;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}