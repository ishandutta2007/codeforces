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

const ll maxn = 5e3 + 17 , md = 1e9 + 7 , inf = 2e16;

ll a[maxn] , cnt[maxn] , dp[maxn];
vector<ll> v[maxn];
bitset<maxn> f[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		v[i].clear(); v[i].shrink_to_fit();
	}
	for(ll i = 0 ; i < n ; i++){
		v[a[i]].push_back(i);
	}
	for(ll i = 0 ; i <= n ; i++){
		f[i][i] = true;
		fill(cnt , cnt + n , 0);
		ll mx = 0;
		for(int j = i + 2 ; j <= n ; j += 2){
			cnt[a[j - 2]]++;
			mx = max(mx , cnt[a[j - 2]]);
			cnt[a[j - 1]]++;
			mx = max(mx , cnt[a[j - 1]]);
			f[i][j] = (mx <= (j - i) / 2);
		}
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		if(v[i].empty()) continue;
		ll vs = sze(v[i]);
		for(ll j = 0 ; j < vs ; j++){
			dp[j] = -inf;
		}
		dp[0] = (f[0][v[i][0]] ? 1 : -inf);
		ans = max(ans , f[v[i][0] + 1][n] * dp[0]);
		for(ll j = 1 ; j < vs ; j++){
			ll h = (f[0][v[i][j]] ? 1 : -inf);
			for(ll k = 0 ; k < j ; k++){
				if(f[v[i][k] + 1][v[i][j]]){
					h = max(h , (dp[k] + 1));
				}
			}
			dp[j] = h;
			ans = max(ans , h * f[v[i][j] + 1][n]);
		}
	}
	cout<<ans<<'\n';
	return;
}

/*
1
7
1 2 3 2 1 3 3
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}