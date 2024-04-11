#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
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

ll cnt[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n , m , q , cur = 0;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		if(v < u) swap(v , u);
		cnt[u]++;
		if(cnt[u] == 1) cur++;
	}
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		ll t;
		cin>>t;
		if(t == 3){
			cout<<n - cur<<'\n';
			continue;
		}
		ll v , u;
		cin>>v>>u; v--; u--; if(v < u) swap(v , u);
		if(t == 1){
			cnt[u]++;
			if(cnt[u] == 1) cur++;
		} else {
			cnt[u]--;
			if(cnt[u] == 0) cur--;
		}
	}
	return 0;
}