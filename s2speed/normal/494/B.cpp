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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e6 + 17 , md = 1e9 + 7 , inf = 1e6;

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

bitset<maxn> mark;
ll f[maxn] , nx[maxn] , dp[maxn] , sf[maxn];
string s , t;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>s>>t;
	ll n = sze(s) , m = sze(t);
	f[0] = -1;
	for(ll i = 1 ; i < m ; i++){
		ll g = f[i - 1];
		while(true){
			if(t[g + 1] == t[i]){
				f[i] = g + 1;
				break;
			}
			if(g == -1){
				f[i] = g;
				break;
			}
			g = f[g];
		}
	}
//	for(ll i = 0 ; i < m ; i++){
//		cout<<f[i]<<' ';
//	}
//	cout<<'\n';
	t += '$';
	ll g = -1 + (s[0] == t[0]);
	mark[0] = (g == m - 1);
	for(ll i = 1 ; i < n ; i++){
		while(true){
			if(s[i] == t[g + 1]){
				g++;
				break;
			}
			if(g == -1){
				break;
			}
			g = f[g];
		}
		if(g == m - 1){
			mark[i - m + 1] = true;
		}
	}
	nx[n] = n + 1;
	for(ll i = n - 1 ; ~i ; i--){
		if(mark[i]){
			nx[i] = i + m;
		} else {
			nx[i] = nx[i + 1];
		}
	}
//	for(ll i = 0 ; i < n ; i++){
//		cout<<nx[i]<<' ';
//	}
//	cout<<'\n';
	sf[n] = dp[n] = sf[n + 1] = dp[n + 1] = 0;
	for(ll i = n - 1 ; ~i ; i--){
		ll h = dp[i + 1] + sf[nx[i]] + max(0ll , n - nx[i] + 1);
		dp[i] = h % md;
		sf[i] = dp[i] + sf[i + 1]; sf[i] -= (sf[i] >= md) * md;
	}
	cout<<dp[0]<<'\n';
	return 0;
}