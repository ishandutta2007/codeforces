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

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e18;

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

ll l[MAXN] , r[MAXN] , cnt[MAXN] , h[MAXN] , a[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(l , 0 , sizeof(l));
	memset(r , 0 , sizeof(r));
	ll n , ans = 0 , m = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	l[0] = 0;
	for(ll i = 1 ; i < n ; i++){
		if(a[i] > a[i - 1]){
			l[i] = l[i - 1] + 1;
		}
	}
	r[n - 1] = 0;
	for(ll i = n - 2 ; i >= 0 ; i--){
		if(a[i] > a[i + 1]){
			r[i] = r[i + 1] + 1;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		h[i] = max(l[i] , r[i]);
		m = max(m , h[i]);
		cnt[h[i]]++;
	}
	if(m % 2 == 1){
		cout<<"0\n";
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		if(l[i] != r[i]) continue;
		if(h[i] != m) continue;
		if(cnt[m] == 1) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/