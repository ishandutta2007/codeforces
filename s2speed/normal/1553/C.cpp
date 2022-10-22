#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
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
	string s , h;
	ll ans = 9;
	cin>>s; h = s;
	for(ll i = 0 ; i < 10 ; i++){
		if(h[i] == '?') h[i] = '0' + (i & 1);
	}
	ll cnt[] = {0 , 0} , rem[] = {5 , 5};
	for(ll i = 0 ; i < 10 ; i++){
		if(h[i] == '1'){
			cnt[i & 1]++;
		}
		rem[i & 1]--;
		if(cnt[0] + rem[0] < cnt[1]){
			ans = i;
			break;
		}
		if(cnt[1] + rem[1] < cnt[0]){
			ans = i;
			break;
		}
	}
	h = s;
	for(ll i = 0 ; i < 10 ; i++){
		if(h[i] == '?') h[i] = '1' - (i & 1);
	}
	cnt[0] = cnt[1] = 0; rem[0] = rem[1] = 5;
	for(ll i = 0 ; i < 10 ; i++){
		if(h[i] == '1'){
			cnt[i & 1]++;
		}
		rem[i & 1]--;
		if(cnt[0] + rem[0] < cnt[1]){
			ans = min(ans , i);
			break;
		}
		if(cnt[1] + rem[1] < cnt[0]){
			ans = min(ans , i);
			break;
		}
	}
	cout<<ans + 1<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}