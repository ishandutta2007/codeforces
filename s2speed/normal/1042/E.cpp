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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e3 + 16 , md = 998244353 , inf = 2e17;

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

ll dv(ll a , ll b){
	return 1ll * a * tav(b , md - 2) % md;
}

ll a[maxn][maxn] , dp[maxn][maxn] , cnt = 0 , sum[2][2] , dps = 0;
vector<ll> x , y , d;
vector<plll> b;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(sum , 0 , sizeof(sum));
	ll n , m , e , w;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
			b.push_back({a[i][j] , {i , j}});
		}
	}
	cin>>e>>w; e--; w--;
	ll p = -1;
	sort(all(b));
	for(auto q : b){
		ll c = q.first , i = q.second.first , j = q.second.second;
		if(c != p){
			for(auto k : x){
				sum[0][0] += k; if(sum[0][0] >= md) sum[0][0] -= md;
				sum[0][1] += 1ll * k * k; sum[0][1] %= md;
			}
			x.clear();
			for(auto k : y){
				sum[1][0] += k; if(sum[1][0] >= md) sum[1][0] -= md;
				sum[1][1] += 1ll * k * k; sum[1][1] %= md;
			}
			y.clear();
			for(auto k : d){
				dps += k; if(dps >= md) dps -= md;
				cnt++;
			}
			d.clear();
		}
		p = c;
		dp[i][j] = dps + sum[0][1] + sum[1][1] + -2ll * sum[0][0] * i + -2ll * sum[1][0] * j + 1ll * i * i * cnt + 1ll * j * j * cnt;
		dp[i][j] %= md; if(dp[i][j] < 0) dp[i][j] += md;
		dp[i][j] = dv(dp[i][j] , cnt);
		x.push_back(i); y.push_back(j); d.push_back(dp[i][j]);
	}
//	for(ll i = 0 ; i < n ; i++){
//		for(ll j = 0 ; j < m ; j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	cout<<dp[e][w]<<'\n';
	return 0;
}