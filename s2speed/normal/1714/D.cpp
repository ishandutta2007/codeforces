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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

string t , s[maxn];
ll dp[maxn] , par[maxn];

bool check(ll j , ll i){
	ll sz = sze(s[i]);
	bool res = true;
	for(ll k = 0 ; k < sz ; k++){
		res &= (t[j + k] == s[i][k]);
	}
	return res;
}

void solve(){
	ll n , ts;
	cin>>t>>n; ts = sze(t);
	fill(dp , dp + ts + 1 , inf);
	for(ll i = 0 ; i < n ; i++){
		cin>>s[i];
	}
	dp[0] = 0;
	for(ll j = 1 ; j <= ts ; j++){
		ll h = j , ind = -1;
		for(ll i = 0 ; i < n ; i++){
			ll sz = sze(s[i]);
			if(j < sz) continue;
			if(check(j - sz , i)){
				if(j - sz < h){
					h = j - sz;
					ind = i;
				}
			}
		}
		ll res = inf;
		for(ll k = h ; k < j ; k++){
			res = min(res , dp[k]);
		}
		dp[j] = res + 1;
		par[j] = ind;
	}
	if(dp[ts] > ts){
		cout<<"-1\n";
		return;
	}
	cout<<dp[ts]<<'\n';
	ll cur = ts;
	while(cur > 0){
		ll sz = sze(s[par[cur]]) , h = -1;
		for(ll k = cur - sz ; k < cur ; k++){
			if(dp[k] == dp[cur] - 1){
				h = k;
				break;
			}
		}
		cout<<par[cur] + 1<<' '<<cur - sz + 1<<'\n';
		cur = h;
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