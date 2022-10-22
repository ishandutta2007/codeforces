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

ll ps[maxn];

void solve(){
	ll n , q;
	string s;
	cin>>n>>q>>s;
	ps[0] = (s[0] == '+' ? 1 : -1);
	for(ll i = 1 ; i < n ; i++){
		ll h = (s[i] == '+') ^ (i & 1);
		if(!h) h--;
		ps[i] = ps[i - 1] + h;
	}
	for(ll i = 0 ; i < q ; i++){
		ll l , r;
		cin>>l>>r; l--;
		ll h = ps[r - 1];
		if(l) h -= ps[l - 1];
		if(h == 0){
			cout<<"0\n";
			continue;
		}
		cout<<2 - ((r - l) & 1)<<'\n';
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