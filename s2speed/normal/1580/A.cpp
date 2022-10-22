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

const ll maxn = 4e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn][maxn] , ps[maxn][maxn] , pr[maxn];

ll cal(ll l1 , ll r1 , ll l2 , ll r2 , bool c){
	ll res = ps[l1][r1];
	if(l2){
		res -= ps[l2 - 1][r1];
	}
	if(r2){
		res -= ps[l1][r2 - 1];
	}
	if(l2 && r2){
		res += ps[l2 - 1][r2 - 1];
	}
	if(!c){
		ll h = (r1 - r2 + 1) * (l1 - l2 + 1) - res;
		res = h;
	}
	if(r1 < r2 || l1 < l2) return 0;
	return res;
}

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		for(ll j = 0 ; j < m ; j++){
			a[i][j] = (s[j] - '0');
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			ps[i][j] = a[i][j];
			if(i){
				ps[i][j] += ps[i - 1][j];
			}
			if(j){
				ps[i][j] += ps[i][j - 1];
			}
			if(i && j){
				ps[i][j] -= ps[i - 1][j - 1];
			}
		}
	}
	ll ans = inf;
	for(ll i = 1 ; i < n ; i++){
		for(ll k = i + 2 ; k < n - 1 ; k++){
			ll d = cal(k , 0 , i , 0 , 0) + cal(k , m - 1 , i , m - 1 , 0) + cal(i - 1 , m - 2 , i - 1 , 1 , 0) + cal(k + 1 , m - 2 , k + 1 , 1 , 0);
			d += cal(k , m - 2 , i , 1 , 1);
			pr[m - 1] = 0;
			for(ll j = m - 2 ; j >= 0 ; j--){
				ll h = cal(k , m - 2 , i , j , 1) + cal(k + 1 , m - 2 , k + 1 , j , 0) + cal(i - 1 , m - 2 , i - 1 , j , 0) + cal(k , m - 1 , i , m - 1 , 0);
				h -= cal(k , j , i , j , 0);
				pr[j] = max(pr[j + 1] , h);
			}
			ans = min(ans , d - pr[3]);
			for(ll j = 1 ; j < m - 3 ; j++){
				ll h = cal(k , j , i , 1 , 1) + cal(k , 0 , i , 0 , 0) + cal(i - 1 , j , i - 1 , 1 , 0) + cal(k + 1 , j , k + 1 , 1 , 0);
				h -= cal(k , j , i , j , 0);
				ans = min(ans , d - h - pr[j + 3]);
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

/*
1
6 9
000000000
001111100
011010000
010110000
010010000
001111100
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}