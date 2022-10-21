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

const ll maxn = 1e6 + 17 , md = 1e9 + 7 , inf = 2e16;

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

string s;
ll cnt[maxn] , cs[maxn] , a[maxn];

void solve(){
	ll n , m , lm;
	cin>>n>>m>>s; lm = n * m;
	for(ll i = 0 ; i < m ; i++) cnt[i] = 0;
	for(ll i = 0 ; i < lm ; i++){
		a[i] = (s[i] == '1');
	}
	ll cur = 0 , r = 0;
	for(ll i = 0 ; i < lm ; i++){
		ll h = i % m;
		cnt[h] += a[i];
		if(cnt[h] == 1 && a[i] == 1){
			r++;
		}
		h = (i >= m ? a[i - m] : 0);
		cur += a[i] - h;
		h = (i >= m ? cs[i - m] : 0);
		cs[i] = (bool)cur + h;
		ll res = r + cs[i];
		cout<<res<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}