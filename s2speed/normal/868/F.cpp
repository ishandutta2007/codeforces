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

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll dp[maxn][25] , cnt[maxn][25] , cur[25] , x[25] , y[25] , a[maxn] , o = 1 , dep;

void dv(ll l , ll r , ll opl , ll opr){
	ll m = (r + l) >> 1 , lm = min(m , opr + 1);
	pll res = {inf , -1};
	while(y[dep] <= m) cur[dep] += cnt[a[y[dep]++]][dep]++;
	for(ll i = opl ; i < lm ; i++){
		while(x[dep] <= i) cur[dep] -= --cnt[a[x[dep]++]][dep];
		res = min(res , {dp[i][o - 1] + cur[dep] , i});
	}
	dp[m][o] = res.first;
	int opt = res.second;
	if(r - l == 1) return;
	dep++;
	dv(l , m , opl , opt); dv(m , r , opt , opr);
	dep--;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(x , 0 , sizeof(x));
	memset(y , 0 , sizeof(y));
	memset(dp , 63 , sizeof(dp));
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	dp[0][0] = 0; cnt[a[0]][0]++;
	for(ll i = 1 ; i < n ; i++){
		dp[i][0] = dp[i - 1][0] + cnt[a[i]][0]++;
	}
	for(; o < k ; o++){
		memset(cnt , 0 , sizeof(cnt));
		memset(x , 0 , sizeof(x));
		memset(y , 0 , sizeof(y));
		memset(cur , 0 , sizeof(cur));
		dep = 0;
		dv(0 , n , o - 1 , n - 1);
	}
	cout<<dp[n - 1][k - 1]<<'\n';
	return 0;
}