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

const ll maxn = 4e3 + 16 , md = 1e9 + 7 , inf = 2e17;

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

vector<piii> it;
int dp[maxn][maxn] , pd[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	memset(pd , 0 , sizeof(pd));
	int n , p;
	cin>>n>>p;
	for(int i = 0 ; i < n ; i++){
		int c , h , t;
		cin>>c>>h>>t; t--;
		it.push_back({t , {c , h}});
	}
	sort(all(it));
	for(int j = it[0].second.first ; j < maxn ; j++){
		dp[0][j] = it[0].second.second;
	}
	for(int i = 1 ; i < n ; i++){
		int pr = it[i].second.first , vl = it[i].second.second;
		if(it[i - 1].first / p == it[i].first / p){
			for(int j = 0 ; j < maxn ; j++){
				dp[i][j] = dp[i - 1][j];
				if(j >= pr){
					dp[i][j] = max(dp[i][j] , dp[i - 1][j - pr] + vl);
				}
			}
			continue;
		}
		for(int j = pr ; j < maxn ; j++){
			dp[i][j] = vl;
		}
	}
	for(int j = it[n - 1].second.first ; j < maxn ; j++){
		pd[n - 1][j] = it[n - 1].second.second;
	}
	for(int i = n - 2 ; i >= 0 ; i--){
		int pr = it[i].second.first , vl = it[i].second.second;
		if(it[i + 1].first / p == it[i].first / p){
			for(int j = 0 ; j < maxn ; j++){
				pd[i][j] = pd[i + 1][j];
				if(j >= pr){
					pd[i][j] = max(pd[i][j] , pd[i + 1][j - pr] + vl);
				}
			}
			continue;
		}
		for(int j = pr ; j < maxn ; j++){
			pd[i][j] = vl;
		}
	}
	int q;
	cin>>q;
	for(int e = 0 ; e < q ; e++){
		int t , v;
		cin>>t>>v; t--;
		int h = n , o = n;
		for(int i = 0 ; i < n ; i++){
			if(it[i].first > t) break;
			if(it[i].first / p == t / p) h = i;
		}
		for(int i = n - 1 ; i >= 0 ; i--){
			if(it[i].first <= t - p) break;
			if(it[i].first / p == t / p - 1) o = i;
		}
		int ans = 0;
		for(int i = 0 ; i <= v ; i++){
			ans = max(ans , dp[h][i] + pd[o][v - i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}