#include<bits/stdc++.h>
#include<fstream>
 
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

const ll maxn = 2e5 + 16 , maxk = 55 , md = 1e9 + 7 , inf = 2e16;

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

db dp[maxn][maxk] , sp[maxn] , pa[maxn];
int opt[maxn][maxk] , o = 2 , a[maxn];
ll ps[maxn];

db ap(int l , int r){
	if(!l) return pa[r];
	db res = pa[r] - pa[l - 1] , h , o;
	h = sp[r] - sp[l - 1];
	res -= ps[l - 1] * h;
	return res;
}

void dvc(int l , int r , int opl , int opr){
	int m = (l + r) / 2 , lm = min(m , opr + 1);
	for(int i = opl ; i < lm ; i++){
		if(dp[i][o - 1] + ap(i + 1 , m) < dp[m][o]){
			dp[m][o] = dp[i][o - 1] + ap(i + 1 , m);
			opt[m][o] = i;
		}
	}
	if(r - l == 1) return;
	dvc(l , m , opl , opt[m][o]);
	dvc(m , r , opt[m][o] , opr);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cout<<fixed<<setprecision(15);
	int n , k;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		for(int j = 2 ; j <= k ; j++){
			dp[i][j] = inf;
		}
	}
	ps[0] = a[0];
	pa[0] = 1;
	sp[0] = (db)1 / a[0];
	dp[0][1] = 1;
	for(int i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + a[i];
		db q = (db)1 * ps[i] / a[i];
		pa[i] = pa[i - 1] + q;
		sp[i] = sp[i - 1] + (db)1 / a[i];
		dp[i][1] = pa[i];
	}
	for(; o <= k ; o++){
		dvc(0 , n , 0 , n);
	}
	cout<<dp[n - 1][k]<<'\n';
	return 0;
}