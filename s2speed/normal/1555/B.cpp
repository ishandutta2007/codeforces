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

void solve(){
	ll H , W , h , w , x1 , x2 , y1 , y2;
	cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
	if(w + x2 - x1 > W && h + y2 - y1 > H){
		cout<<"-1\n";
		return;
	}
	ll x , y;
	x = w; y = h;
	ll ans = inf;
	if(w + x2 - x1 <= W){
		ans = min(ans , x - x1);
		x = W - w;
		ans = min(ans , x2 - x);
	}
	if(h + y2 - y1 <= H){
		ans = min(ans , y - y1);
		y = H - h;
		ans = min(ans , y2 - y);
	}
	cout<<(ans < 0 ? 0 : ans)<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}