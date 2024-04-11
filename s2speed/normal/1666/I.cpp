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

const ll maxn = 5e3 + 17 , md = 998244353 , inf = 2e18;

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

ll inp;

void scan(ll i , ll j){
	cout<<"SCAN "<<i + 1<<' '<<j + 1<<endl;
	cin>>inp;
	return;
}

void dig(ll i , ll j){
	cout<<"DIG "<<i + 1<<' '<<j + 1<<endl;
	cin>>inp;
	return;
}

void solve(){
	ll n , m , sumx , sumy;
	cin>>n>>m;
	scan(0 , 0);
	ll h0 , hx , hy;
	h0 = inp;
	scan(0 , m - 1);
	hx = inp;
	sumy = (hx + h0 - 2 * (m - 1)) / 2;
	sumx = h0 - sumy;
	ll midx , midy , difx , dify;
	midx = sumx / 2;
	midy = sumy / 2;
	scan(0 , midx);
	difx = inp - sumy;
	scan(midy , 0);
	dify = inp - sumx;
	ll x1 , x2 , y1 , y2;
	x1 = (sumx - difx) / 2; x2 = x1 + difx;
	y1 = (sumy - dify) / 2; y2 = y1 + dify;
//	cout<<x1<<' '<<x2<<'\n'<<y1<<' '<<y2<<endl;
	dig(y1 , x1);
	if(inp){
		dig(y2 , x2);
		return;
	} else {
		dig(y1 , x2);
		dig(y2 , x1);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}