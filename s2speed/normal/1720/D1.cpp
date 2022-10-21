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

const ll maxn = 4e6 + 17 , md = 1e9 + 7 , inf = 2e16;

ll tr[maxn][2] , f[maxn][2] , o;

void add(ll x , ll y , ll k){
	ll v = 0;
	for(ll j = 29 ; ~j ; j--){
		bool h = x & (1 << j) , t = y & (1 << j);
		if(tr[v][h] == -1){
			tr[v][h] = o;
			tr[o][0] = tr[o][1] = f[o][0] = f[o][1] = -1;
			o++;
		}
		v = tr[v][h];
		f[v][t] = max(f[v][t] , k);
	}
	return;
}

ll cal(ll x , ll y){
	ll v = 0 , res = 0;
	for(ll j = 29 ; ~j && ~v ; j--){
		bool h = x & (1 << j) , t = y & (1 << j);
		if(tr[v][!h] != -1){
			res = max(res , f[tr[v][!h]][!t]);
		}
		v = tr[v][h];
	}
	return res;
}

ll dp[maxn] , a[maxn];

void solve(){
	tr[0][0] = tr[0][1] = -1; o = 1;
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		dp[i] = cal(a[i] ^ i , a[i]) + 1;
		ans = max(ans , dp[i]);
		add(a[i] ^ i , i , dp[i]);
	}
	cout<<ans<<'\n';
	return;
}

/*
1
2
1 2
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}