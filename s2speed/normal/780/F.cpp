#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll n;

struct matrix {

	bitset<maxn> r[maxn] , c[maxn];

	void identity(){
		for(int i = 0 ; i < n ; i++) r[i][i] = c[i][i] = true;
		return;
	}

	friend matrix operator* (matrix a , matrix b){
		matrix res;
		for(ll i = 0 ; i < n ; i++){
			for(ll j = 0 ; j < n ; j++){
				bitset<maxn> tmp = a.r[i] & b.c[j];
				res.r[i][j] = res.c[j][i] = tmp.any();
			}
		}
		return res;
	}

};

matrix dp[60][2];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		bool c;
		cin>>v>>u>>c; v--; u--;
		dp[0][c].r[v][u] = dp[0][c].c[u][v] = true;
	}
	for(ll j = 1 ; j < 60 ; j++){
		dp[j][0] = dp[j - 1][0] * dp[j - 1][1];
		dp[j][1] = dp[j - 1][1] * dp[j - 1][0];
	}
	ll ans = 0;
	bool t = false;
	matrix cur;
	cur.identity();
	for(ll j = 59 ; j >= 0 ; j--){
		matrix tmp = cur * dp[j][t];
		if(tmp.r[0].any()){
			t ^= 1;
			cur = tmp;
			ans += (1ll << j);
		}
	}
	if(ans > 1e18){
		cout<<"-1\n";
	} else {
		cout<<ans<<'\n';
	}
	return 0;
}