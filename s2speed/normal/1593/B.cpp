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

void solve(){
	string s;
	cin>>s;
	ll cnt[4];
	memset(cnt , 0 , sizeof(cnt));
	ll n = sze(s);
	for(ll i = n - 1 ; i >= 0 ; i--){
		if(s[i] == '0'){
			if(cnt[0] == 1){
				cout<<n - (i + 2)<<'\n';
				return;
			}
			cnt[0] = cnt[2] = 1;
		}
		if(s[i] == '5'){
			cnt[1] = cnt[3] = 1;
		}
		if(s[i] == '2'){
			if(cnt[1] == 1){
				cout<<n - (i + 2)<<'\n';
				return;
			}
		}
		if(s[i] == '7'){
			if(cnt[3] == 1){
				cout<<n - (i + 2)<<'\n';
				return;
			}
		}
		if(s[i] == '5'){
			if(cnt[2] == 1){
				cout<<n - (i + 2)<<'\n';
				return;
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T; 
	while(T--) solve();
	return 0;
}