#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
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

ll n , m;
ll a[maxn] , b[maxn];

bool check(ll z){
	ll x = 0;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		if(b[x] < a[i]){
			if(a[i] - z > b[x]) return false;
			h = max(a[i] + (b[x] + z - a[i]) / 2ll , b[x] + z - (a[i] - b[x]));
		} else {
			h = a[i] + z;
		}
		while(b[x] <= h) x++;
	}
	return (x == m);
}		

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m; b[m] = inf;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i];
	}
	ll l = -1 , r = 2e10;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<l + 1<<'\n';
	return 0;
}