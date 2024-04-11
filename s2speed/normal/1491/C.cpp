#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , md = 998244353 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

ll a[MAXN] , m[MAXN];

void solve(){
	memset(m , 0 , sizeof(m));
	ll n , ans = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		if(i > 0){
			m[i] = m[i - 1] - a[i - 1] + 1;
		}
		for(ll j = i - 2 ; j >= 0 ; j--){
			m[i] += (a[j] + j >= i);
		}
		ll q = a[i] - 1;
		if(m[i] >= q) continue;
		ans += q - m[i];
		m[i] = q;
	}
	cout<<ans<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/