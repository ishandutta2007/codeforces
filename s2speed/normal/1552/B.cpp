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

ll a[maxn][5];

bool cmp(ll i , ll j){
	ll cnt = 0;
	for(ll k = 0 ; k < 5 ; k++){
		cnt += (a[i][k] <= a[j][k]);
	}
	return (cnt >= 3);
}

void solve(){
	ll n , cur = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
	}
	for(ll i = 1 ; i < n ; i++){
		if(cmp(i , cur)) cur = i;
	}
	bool ans = true;
	for(ll i = 0 ; i < n ; i++){
		ans &= cmp(cur , i);
	}
	cout<<(ans ? cur + 1 : -1)<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}