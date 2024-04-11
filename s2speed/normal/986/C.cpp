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

const ll maxn = 5e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll n , m , lm;
bitset<maxn> a , mark , b;

void DFS(ll r){
	mark[r] = true;
	ll h = r ^ lm;
	if(a[h] && !b[h]){
		b[h] = true;
		if(!mark[h]) DFS(h);
	}
	for(ll j = 0 ; j < n ; j++){
		if((1 << j) & r) continue;
		h = r ^ (1 << j);
		if(mark[h]) continue;
		DFS(h);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m; lm = (1 << n) - 1;
	for(ll i = 0 ; i < m ; i++){
		ll h;
		cin>>h; a[h] = true;
	}
	ll ans = 0;
	for(ll i = 0 ; i <= lm ; i++){
		if(!a[i]) continue;
		if(b[i]) continue;
		ans++;
		b[i] = true;
		DFS(i);
	}
	cout<<ans<<'\n';
	return 0;
}