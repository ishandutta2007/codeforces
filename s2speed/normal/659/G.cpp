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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll a[maxn] , cur = 0 , ans = 0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(a , 63 , sizeof(a));
	ll n;
	cin>>n;
	if(n == 1){
		ll h;
		cin>>h;
		cout<<h - 1<<'\n';
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--; ans += a[i];
	}
	cur = min(a[0] , a[1]);
	for(ll i = 1 ; i < n ; i++){
		ans += 1ll * cur * min(a[i] , a[i - 1]) % md;
		if(i != n - 1){
			cur *= min(a[i] , min(a[i - 1] , a[i + 1])); cur %= md;
			cur += min(a[i] , a[i + 1]); if(cur > md) cur -= md;
		}
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}