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

ll a[maxn] , b[maxn] , c[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , -31 , sizeof(c));
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll j = 0 ; j < m ; j++){
		cin>>b[j];
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			c[i] = max(c[i] , 1ll * a[i] * b[j]);
		}
	}
	sort(c , c + n);
	cout<<c[n - 2]<<"\n";
	return 0;
}