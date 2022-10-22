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

const ll maxn = 2e5 , md = 1e9 + 7 , inf = 2e16;

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
vector<ll> a;
ll ps[maxn];

db f(ll i , ll k){
	if(i - k - 1 < -1) return -inf;
	if(n - k - 1 < i) return -inf;
	db res = ps[i] - (i - k - 1 == -1 ? 0 : ps[i - k - 1]) + ps[n - 1] - ps[n - 1 - k];
	res /= 2 * k + 1; res -= a[i];
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n; a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	sort(all(a));
	ps[0] = a[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + a[i];
	}
	ll ind = -1 , k = -1;
	db ans = -1;
	for(ll i = 0 ; i < n ; i++){
		ll l = -1 , r = n;
		while(l < r - 1){
			ll m = (r + l) >> 1;
			if(f(i , m) >= f(i , m + 1)){
				r = m;
			} else {
				l = m;
			}
		}
		if(f(i , l + 1) > ans){
			ans = f(i , l + 1);
			ind = i;
			k = l + 1;
		}
	}
	cout<<2 * k + 1<<'\n';
	for(ll i = ind - k ; i <= ind ; i++){
		cout<<a[i]<<' ';
	}
	for(ll i = n - 1 ; i > n - 1 - k ; i--){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
	return 0;
}