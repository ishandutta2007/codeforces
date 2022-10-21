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

const ll maxn = 212 , md = 1e9 + 7 , inf = 2e18;

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

ll a[maxn][maxn] , dp[maxn][maxn] , rt[maxn][maxn] , sum[maxn][maxn] , ps[maxn][maxn] , sf[maxn][maxn] , pr[maxn];

void DFS(ll l , ll r , ll par){
	if(l == r) return;
	if(l == r - 1){
		pr[l] = par;
		return;
	}
	ll v = rt[l][r];
	pr[v] = par;
	DFS(l , v , v); DFS(v + 1 , r , v);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	memset(sum , 0 , sizeof(sum));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			cin>>a[i][j];
		}
	}
	for(ll i = 0 ; i < n ; i++){
		ps[i][0] = a[i][0];
		for(ll j = 1 ; j < n ; j++){
			ps[i][j] = ps[i][j - 1] + a[i][j];
		}
		sf[i][n] = 0;
		for(ll j = n - 1 ; ~j ; j--){
			sf[i][j] = sf[i][j + 1] + a[i][j];
		}
	}
	for(ll l = 0 ; l < n ; l++){
		for(ll r = l + 1 ; r <= n ; r++){
			for(ll k = l ; k < r ; k++){
				sum[l][r] += (l == 0 ? 0 : ps[k][l - 1]) + sf[k][r];
			}
		}
	}
	for(ll l = 2 ; l <= n ; l++){
		for(ll i = 0 ; i + l <= n ; i++){
			ll j = i + l;
			ll res = inf;
			for(ll k = i ; k < j ; k++){
				ll h = dp[i][k] + sum[i][k] + dp[k + 1][j] + sum[k + 1][j];
				if(h < res){
					res = h;
					rt[i][j] = k;
				}
			}
			dp[i][j] = res;
		}
	}
	DFS(0 , n , -1);
	for(ll i = 0 ; i < n ; i++){
		cout<<pr[i] + 1<<' ';
	}
	cout<<'\n';
	return 0;
}