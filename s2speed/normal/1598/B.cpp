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

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> a[maxn];
ll cnt[5];

void solve(){
	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < 5 ; j++){
			ll h;
			cin>>h;
			a[i][j] = h;
			cnt[j] += h;
		}
	}
	for(ll i = 0 ; i < 5 ; i++){
		if(cnt[i] < n / 2) continue;
		for(ll j = i + 1 ; j < 5 ; j++){
			if(cnt[j] < n / 2) continue;
			bool res = true;
			for(ll k = 0 ; k < n ; k++){
				res &= (a[k][i] | a[k][j]);
			}
			if(!res) continue;
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}