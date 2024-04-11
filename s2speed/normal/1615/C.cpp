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

inline ll tav(ll n , ll k){
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

string s , t;

void solve(){
	ll n , cns = 0 , cnt = 0;
	cin>>n>>s>>t;
	for(ll i = 0 ; i < n ; i++){
		cns += (s[i] ^ '0');
		cnt += (t[i] ^ '0');
	}
	if(cnt != cns && cnt != n - cns + 1){
		cout<<"-1\n";
		return;
	}
	ll ans = 0;
	if(cnt != cns){
		ll j = -1;
		for(ll i = 0 ; i < n ; i++){
			if((s[i] ^ '0') && (t[i] ^ '0')){
				j = i;
				break;
			}
		}
		for(ll i = 0 ; i < n ; i++){
			if(j == -1 && s[i] == '1'){
				j = i;
			}
			if(j == i) continue;
			if(s[i] == '1'){
				s[i] = '0';
			} else {
				s[i] = '1';
			}
		}
		ans++;
	}
	for(ll i = 0 ; i < n ; i++){
		if(t[i] == '1' && s[i] == '0') ans += 2;
	}
	if(2 * cns - 1 == n){
		ans = min(ans , n - ans);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}