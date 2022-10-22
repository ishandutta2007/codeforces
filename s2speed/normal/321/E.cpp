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

const ll maxn = 4e3 + 16 , maxk = 8e2 + 16 , md = 1e9 + 7 , inf = 2e15;

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

int ps[maxn][maxn] , a[maxn][maxn] , dp[maxn][maxk] , o = 2 , opt[maxn][maxk];

void dvc(int l , int r , int opl , int opr){
	int m = (r + l) / 2 , lm = min(m , opr + 1);
	for(int i = opl ; i < lm ; i++){
		if(dp[i][o - 1] + ps[i + 1][m] < dp[m][o]){
			opt[m][o] = i;
			dp[m][o] = dp[i][o - 1] + ps[i + 1][m];
		}
	}
	if(r - l == 1){
		return;
	}
	dvc(l , m , opl , opt[m][o]);
	dvc(m , r , opt[m][o] , opr);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(ps , 0 , sizeof(ps));
	memset(dp , 63 , sizeof(dp));
	int n , k;
	string s;
	cin>>n>>k; getline(cin , s);
	for(int i = 0 ; i < n ; i++){
		getline(cin , s);
		for(int j = 0 ; j < n ; j++){
			a[i][j] = s[j << 1] - '0';
		}
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		for(int j = i + 1 ; j < n ; j++){
			ps[i][j] = ps[i][j - 1] + ps[i + 1][j] - ps[i + 1][j - 1] + a[i][j];
		}
	}
	for(int i = 0 ; i < n ; i++){
		dp[i][1] = ps[0][i];
	}
	for(; o <= k ; o++){
		dvc(0 , n , 0 , n);
	}
	cout<<dp[n - 1][k]<<'\n';
	return 0;
}

/*
7 3
0 0 1 1 1 1 1
0 0 1 1 1 1 1
1 1 0 0 0 1 1
1 1 0 0 0 1 1
1 1 0 0 0 1 1
1 1 1 1 1 0 0
1 1 1 1 1 0 0
*/