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

ll a[maxn] , rmq[maxn][20] , ps[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(rmq , 0 , sizeof(rmq));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		rmq[i][0] = a[i];
	}
	for(ll j = 1 , o = 1 ; o < n ; j++ , o <<= 1){
		for(ll i = 0 ; i < o ; i++) rmq[i][j] = rmq[i][j - 1];
		for(ll i = o ; i < n ; i++){
			ll h = i - o;
			rmq[i][j] = gcd(rmq[i][j - 1] , rmq[h][j - 1]);
		}
	}
	ps[0] = a[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = gcd(ps[i - 1] , a[i]);
	}
	ll cur = 0 , ls = -1;
	for(ll i = 0 ; i < n ; i++){
		if(ps[i] > i + 1){
			cout<<cur<<' ';
			continue;
		}
		ll v = i , c = 0 , l = 0;
		for(ll j = 19 , o = (1 << 19) ; j >= 0 ; j-- , o >>= 1){
			if(v - o < 0) continue;
			ll h = gcd(c , rmq[v][j]);
			if(h > l + o){
				c = h;
				v -= o;
				l += o;
			}
		}
		c = gcd(c , a[v]);
		if(v > ls){
			if(c == l + 1){
				cur++;
				ls = i;
			}
		}
		cout<<cur<<' ';
	}
	cout<<'\n';
	return 0;
}