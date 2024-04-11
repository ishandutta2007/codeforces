#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 5e2 + 17 , md = 1e9 + 7 , inf = 2e16;

string s , t , r;
ll dp[maxn][maxn] , f[maxn << 1] , nx[maxn << 1] , ps[maxn][maxn] , res[maxn];
bitset<maxn> o;

void solve(){
	o.reset();
	memset(nx , -1 , sizeof(nx));
	memset(res , 0 , sizeof(res));
	ll n , m;
	cin>>s>>t; n = sze(s); m = sze(t);
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			dp[i][j] = ps[i][j] = 0;
		}
	}
	r = t + '#' + s;
	ll rs = n + m + 1;
	f[0] = 0;
	for(ll i = 1 ; i < rs ; i++){
		ll g = f[i - 1];
		while(true){
			if(r[i] == r[g]){
				g++;
				break;
			}
			if(g == 0) break;
			g = f[g - 1];
		}
		f[i] = g;
	}
	for(ll i = m + 1 ; i < rs ; i++){
		if(f[i] == m){
			o[i - (m + 1) - (m - 1)] = true;
//			cout<<i - (m << 1)<<'\n';
		}
	}
	for(ll i = n - 1 ; ~i ; i--){
		if(o[i]){
			nx[i] = i;
		} else {
			nx[i] = nx[i + 1];
		}
	}
	if(nx[0] == -1){
		cout<<"0 1\n";
		return;
	}
	ps[nx[0]][0] = 1;
	for(ll i = nx[0] ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			ps[i][j] += (i > 0 ? ps[i - 1][j] : 0);
		}
		if(!o[i]) continue;
		for(ll j = 0 ; j < n ; j++){
			dp[i][j + 1] = (ps[i][j] - (i >= m ? ps[i - m][j] : 0)) % md; dp[i][j + 1] += (dp[i][j + 1] < 0) * md;
		}
		ll h = nx[i + m];
		if(h != -1){
			for(ll j = 1 ; j <= n ; j++){
				ps[h][j] += dp[i][j];
			}
		} else {
			for(ll j = 1 ; j <= n ; j++){
				res[j] += dp[i][j];
			}
		}
	}
	ll ans;
	for(ll j = 1 ; j <= n ; j++){
		if(res[j] > 0){
			ans = res[j] % md;
			cout<<j<<' ';
			break;
		}
	}
	cout<<ans<<'\n';
	return;
}

/*
1
abababacababa
aba
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}