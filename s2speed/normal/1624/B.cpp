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

void solve(){
	ll a , b , c;
	cin>>a>>b>>c;
	ll d = c - b;
	if((b - d) % a == 0 && (b - d) > 0){
		cout<<"YES\n";
		return;
	}
	d = b - a;
	if((b + d) % c == 0 && (b + d) > 0){
		cout<<"YES\n";
		return;
	}
	d = c - a;
	if(d % 2 != 0){
		cout<<"NO\n";
		return;
	}
	d /= 2;
	if((a + d) % b == 0){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}