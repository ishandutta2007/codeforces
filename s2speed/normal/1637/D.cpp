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

const ll maxn = 2e4 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , b[maxn];
vector<ll> v;
bitset<maxn> dp , tmp;

void solve(){
	v.clear();
	dp.reset();
	ll n , ans = 0 , sum = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		ans += a[i] * a[i];
		sum += a[i];
		v.push_back(a[i]);
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
		ans += b[i] * b[i];
		sum += b[i];
		v.push_back(b[i]);
	}
	ans *= n - 1;
	for(ll i = 0 ; i < 2 * n ; i++){
		for(ll j = i + 1 ; j < 2 * n ; j++){
			ans += 2 * v[i] * v[j];
		}
	}
	dp[0] = true;
	for(ll i = 0 ; i < n ; i++){
		tmp = (dp << a[i]) | (dp << b[i]);
		dp = tmp;
	}
	for(ll i = sum / 2 ; ~i ; i--){
		if(dp[i]){
			ans -= 2 * i * (sum - i);
			break;
		}
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