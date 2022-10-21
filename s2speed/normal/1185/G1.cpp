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

const ll maxn = 2.5e3 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll g[52][52][52][3] , f[52][52][52] , dp[3][52][maxn];
vector<ll> v[3];
set<ll> s[3][52];
bitset<maxn> b[3][52];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll dv = tav(2 , md - 2);
	ll n , x;
	cin>>n>>x;
	g[0][0][0][0] = g[0][0][0][1] = g[0][0][0][2] = 1;
	int cnt = 0;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= n ; j++){
			for(int k = 0 ; k <= n ; k++){
				if(i + j + k == 0 || i + j + k > n) continue;
				ll h[] = {0 , 0 , 0};
				if(i){
					h[1] += g[i - 1][j][k][0] * i;
					h[2] += g[i - 1][j][k][0] * i;
				}
				if(j){
					h[0] += g[i][j - 1][k][1] * j;
					h[2] += g[i][j - 1][k][1] * j;
				}
				if(k){
					h[0] += g[i][j][k - 1][2] * k;
					h[1] += g[i][j][k - 1][2] * k;
				}
				for(int t = 0 ; t < 3 ; t++){
					h[t] %= md;
					g[i][j][k][t] = h[t];
					f[i][j][k] += h[t];
				}
				f[i][j][k] %= md;
				f[i][j][k] *= dv; f[i][j][k] %= md;
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		ll h , t;
		cin>>h>>t; t--;
		v[t].push_back(h);
	}
	if(sze(v[0]) > sze(v[1])){
		swap(v[0] , v[1]);
	}
	if(sze(v[1]) > sze(v[2])){
		swap(v[1] , v[2]);
	}
	if(sze(v[0]) > sze(v[1])){
		swap(v[0] , v[1]);
	}
	for(ll t = 0 ; t < 3 ; t++){
		ll vs = sze(v[t]);
		s[t][0].insert(0);
		b[t][0][0] = true;
		dp[t][0][0] = 1;
		for(ll i = 0 ; i < vs ; i++){
			ll a = v[t][i];
			for(ll j = i + 1 ; j ; j--){
				auto et = s[t][j - 1].end();
				for(auto it = s[t][j - 1].begin() ; it != et ; it++){
					ll h = *it + a;
					dp[t][j][h] += dp[t][j - 1][*it]; dp[t][j][h] -= (dp[t][j][h] >= md) * md;
					if(!b[t][j][h]){
						b[t][j][h] = true;
						s[t][j].insert(h);
					}
				}
			}
		}
	}
	ll ans = 0;
	for(ll i = 0 ; i <= n ; i++){
		for(ll j = 0 ; j <= n ; j++){
			for(ll k = 0 ; k <= n ; k++){
				ll res = 0;
				if(f[i][j][k] == 0) continue;
				for(auto it = s[0][i].begin() ; it != s[0][i].end() ; it++){
					for(auto jt = s[1][j].begin() ; jt != s[1][j].end() ; jt++){
						if(*it + *jt > x) break;
						ll o = x - *it - *jt;
						ll h = dp[0][i][*it] * dp[1][j][*jt] % md * dp[2][k][o] % md;
						res += h;
					}
				}
				res %= md;
				res *= f[i][j][k]; res %= md;
				ans += res;
			}
		}
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}