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

bool check(ll a , ll b , ll c , ll d){
	if(a >= b && b >= c) return false;
	if(a >= b && b >= d) return false;
	if(a >= c && c >= d) return false;
	if(b >= c && c >= d) return false;
	if(a <= b && b <= c) return false;
	if(a <= b && b <= d) return false;
	if(a <= c && c <= d) return false;
	if(b <= c && c <= d) return false;
	return true;
}

ll a[maxn];

void solve(){
	ll n , ans = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ans = 2ll * n - 1;
	for(ll i = 0 ; i < n - 2 ; i++){
		if(a[i] >= a[i + 1] && a[i + 1] >= a[i + 2]) continue;
		if(a[i] <= a[i + 1] && a[i + 1] <= a[i + 2]) continue;
		ans++;
	}
	for(ll i = 0 ; i < n - 3 ; i++){
		ans += check(a[i] , a[i + 1] , a[i + 2] , a[i + 3]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}