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

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , sum = 0 , m = inf , s = -inf;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		if(a[i] >= 0){
			sum += a[i];
			if(a[i] & 1){
				m = min(m , a[i]);
			}
		} else {
			if(a[i] % 2 == -1){
				s = max(s , a[i]);
			}
		}
	}
	if(sum & 1){
		cout<<sum<<'\n';
		return 0;
	}
	cout<<sum + max(-m , s)<<'\n';
	return 0;
}