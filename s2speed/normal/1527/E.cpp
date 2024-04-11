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

const ll maxn = 35e3 + 16 , md = 998244353 , inf = 2e17;

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

ll dp[maxn] , pd[maxn] , a[maxn] , lst[maxn] , nt[maxn] , pr[maxn] , x[20] , y[20] , cur[20] , dep = 0;

void dv(ll l , ll r , ll opl , ll opr){
	ll m = (r + l) >> 1 , lm = min(opr + 1 , m);
	while(y[dep] <= m){
		if(pr[y[dep]] >= x[dep]) cur[dep] += y[dep] - pr[y[dep]];
		y[dep]++;
	}
	pll res = {inf , inf};
	for(ll i = opl ; i < lm ; i++){
		while(x[dep] <= i){
			ll h = nt[x[dep]];
			if(h < y[dep]) cur[dep] -= h - x[dep];
			x[dep]++;
		}
		res = min(res , {pd[i] + cur[dep] , i});
	}
	dp[m] = res.first;
	if(r - l == 1) return;
	dep++;
	dv(l , m , opl , res.second);
	dv(m , r , res.second , opr);
	dep--;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(lst , 63 , sizeof(lst));
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	for(ll i = n - 1 ; i >= 0 ; i--){
		nt[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	memset(lst , -1 , sizeof(lst));
	for(ll i = 0 ; i < n ; i++){
		pr[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	for(ll i = 0 ; i < n ; i++){
		pd[i] = pd[i - 1];
		if(pr[i] >= 0) pd[i] += i - pr[i];
	}
	if(k == 1){
		cout<<pd[n - 1]<<'\n';
		return 0;
	}
	for(ll j = 1 ; j < k ; j++){
		memset(x , 0 , sizeof(x)); memset(y , 0 , sizeof(y)); memset(cur , 0 , sizeof(cur));
		dv(0 , n , 0 , n);
		memcpy(pd , dp , sizeof(pd));
	}
	cout<<dp[n - 1]<<'\n';
	return 0;
}