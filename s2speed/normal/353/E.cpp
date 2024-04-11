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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> a , b;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	string s;
	cin>>s; n = sze(s);
	for(ll i = 0 ; i < n ; i++){
		a[i] = (s[i] == '1');
	}
	a[n] = a[0];
	for(ll i = 0 ; i < n ; i++){
		b[i] = a[i] ^ a[i + 1];
	}
	if(b.count() == n){
		cout<<n / 2<<'\n';
		return 0;
	}
	b[n] = b[0];
	ll h;
	for(h = 1; h <= n ; h++){
		if(b[h] & !b[h - 1]) break;
	}
	ll ans = 0 , cnt = 0;
	for(ll i = h ; i != h || !ans ; i++){
		if(!b[i]){
			cnt = 0;
		} else {
			if(!b[i - 1]){
				ans++;
			} else {
				cnt++;
				if(cnt == 2){
					ans++;
					cnt = 0;
				}
			}
		}
		if(i == n) i = 0;
	}
	cout<<ans<<'\n';
	return 0;
}