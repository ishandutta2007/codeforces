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

const ll MAXN = 4e5 + 15 , md = 1e9 + 7 , inf = 1e9;

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

ll ps[MAXN] , a[MAXN] , st[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , t , k;
	cin>>n>>t>>k;
	if(k > n - t){
		cout<<"-1\n";
		return 0;
	}
	for(ll i = 0 ; i < t ; i++){
		cin>>a[i];
	}
	ps[t - 1] = a[t - 1];
	for(ll i = t - 2 ; i >= 0 ; i--){
		ps[i] = ps[i + 1] + max(0ll , a[i] - a[i + 1]);
	}
	if(k < ps[0]){
		cout<<"-1\n";
		return 0;
	}
	cout<<n<<'\n';
	st[0] = 2; st[t] = n + 1;
	for(ll i = 1 ; i < t ; i++){
		st[i] = st[i - 1] + a[i - 1];
	}
	for(ll i = 1 ; i <= a[0] ; i++){
		cout<<"1 "<<i + 1<<'\n';
	}
	for(ll i = 0 ; i < t - 1 ; i++){
		ll x = st[i] , y = st[i + 1];
		x += max(0ll , a[i] - a[i + 1]);
		k -= max(0ll , a[i] - a[i + 1]);
		while(x < st[i + 1] - 1){
			if(k > ps[i + 1]){
				k--;
				x++;
				continue;
			}
			cout<<x++<<' '<<y++<<'\n';
		}
		while(y < st[i + 2]){
			cout<<x<<' '<<y++<<'\n';
		}
	}
	return 0;
}

/*

*/