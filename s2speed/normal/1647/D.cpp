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

const ll maxn = 1e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bool prime(ll x){
	ll sq = sqrt(x);
	for(ll i = 2 ; i <= sq ; i++){
		if(x % i == 0) return false;
	}
	return true;
}

void solve(){
	ll x , d , cnt = 0;
	cin>>x>>d;
	ll h = x;
	while(h % d == 0){
		h /= d;
		cnt++;
	}
	if(cnt < 2){
		cout<<"No\n";
		return;
	}
	if(!prime(h)){
		cout<<"YES\n";
		return;
	}
	if(cnt == 2){
		cout<<"NO\n";
		return;
	}
	if(prime(d)){
		cout<<"NO\n";
		return;
	}
	if(d % h != 0){
		cout<<"YES\n";
		return;
	}
	if(h == 1){
		cout<<(prime(d) ? "NO\n" : "YES\n");
		return;
	}
	if(!prime(d / h)){
		cout<<"YES\n";
		return;
	}
	ll sq = sqrt(d) , p;
	bool f;
	for(ll i = 2 ; i <= sq ; i++){
		if(d % i == 0){
			p = i;
			break;
		}
	}
	ll o = p;
	while(o < d) o *= p;
	f = (o != d);
	if(f){
		cout<<"YES\n";
		return;
	}
	cout<<(cnt == 3 ? "NO\n" : "YES\n");
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}