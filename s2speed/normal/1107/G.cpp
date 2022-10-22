#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll n;
ll rmq[maxn][20] , qmr[maxn][20] , lb[maxn];
ll a[maxn] , b[maxn] , c[maxn] , ps[maxn] , l[maxn] , r[maxn];
vector<pll> v;

void rmq_build(){
	memset(rmq , -63 , sizeof(rmq));
	memset(qmr , 63 , sizeof(qmr));
	for(ll i = 0 ; i < n ; i++){
		rmq[i][0] = qmr[i][0] = ps[i];
	}
	for(ll j = 1 ; j < 20 ; j++){
		ll h = 1 << (j - 1) , lm = n - h;
		for(ll i = 0 ; i < lm ; i++){
			rmq[i][j] = max(rmq[i][j - 1] , rmq[i + h][j - 1]);
			qmr[i][j] = min(qmr[i][j - 1] , qmr[i + h][j - 1]);
		}
	}
	ll h = 2 , cnt = 0;
	for(ll i = 1 ; i <= n ; i++){
		lb[i] = cnt;
		if(i == h){
			cnt++;
			h <<= 1;
		}
	}
	return;
}

pll cal(ll l , ll r){
	bool ch = (l == -1);
	if(ch) l = 0;
	if(r == l) return {0 , 0};
	ll j = lb[r - l] , a , b;
	a = max(rmq[l][j] , rmq[r - (1 << j)][j]);
	b = min(qmr[l][j] , qmr[r - (1 << j)][j]);
	if(ch){
		a = max(a , 0ll);
		b = min(b , 0ll);
	}
	return {a , b};
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll val , ans = 0;
	cin>>n>>val;
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i]>>a[i];
		a[i] = val - a[i];
		ans = max(ans , a[i]);
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		c[i] = b[i + 1] - b[i];
	}
	ps[0] = a[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + a[i];
	}
	rmq_build();
	for(ll i = 0 ; i < n - 1 ; i++){
		ll h = -1;
		while(!v.empty()){
			if(v.back().first > c[i]){
				h = v.back().second;
				break;
			}
			v.pop_back();
		}
		l[i] = h;
		v.push_back({c[i] , i});
	}
	v.clear();
	for(ll i = n - 2 ; i >= 0 ; i--){
		ll h = n - 1;
		while(!v.empty()){
			if(v.back().first > c[i]){
				h = v.back().second;
				break;
			}
			v.pop_back();
		}
		r[i] = h;
		v.push_back({c[i] , i});
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		ll v , u;
		pll p;
		p = cal(i + 1 , r[i] + 1);
		v = p.first;
		p = cal(l[i] , i);
		u = p.second;
		ans = max(ans , v - u - 1ll * c[i] * c[i]);
	}
	cout<<ans<<'\n';
	return 0;
}