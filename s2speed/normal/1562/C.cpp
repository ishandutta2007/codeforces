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

void solve(){
	ll n , l = -1 , r = n;
	string s;
	cin>>n>>s;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '0'){
			l = i;
			break;
		}
	}
	if(l == -1){
		cout<<"1 "<<n - 1<<' '<<"2 "<<n<<'\n';
		return;
	}
	for(ll i = n - 1 ; i >= 0 ; i--){
		if(s[i] == '0'){
			r = i;
			break;
		}
	}
	if(n - 1 - l >= (n + 1) / 2){
		cout<<l + 2<<' '<<n<<' '<<l + 1<<' '<<n<<'\n';
		return;
	}
	cout<<"1 "<<r + 1<<" 1 "<<r<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}