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
struct plll { ll x , y , z; };
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e17;

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

int dp[maxn] , a[maxn] , b[maxn] , par[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(a , -1 , sizeof(a));
	memset(b , -1 , sizeof(b));
	int n;
	cin>>n; n++;
	fill(dp , dp + n , 1);
	for(int i = 1 ; i < n ; i++){
		cin>>par[i]; par[i]--;
		int v = i;
		while(par[v] != 0){
			int h = dp[par[v]];
			if(a[par[v]] == -1){
				a[par[v]] = v;
				break;
			}
			if(b[par[v]] == -1 && a[par[v]] != v){
				b[par[v]] = v;
				dp[par[v]] = max(dp[a[par[v]]] , dp[v] + 1);
				if(dp[par[v]] == h) break;
				v = par[v];
				continue;
			}
			if(a[par[v]] != v && b[par[v]] != v){
				if(dp[v] > dp[b[par[v]]]) b[par[v]] = v;
			}
			if(b[par[v]] == v){
				if(dp[v] > dp[a[par[v]]]) swap(a[par[v]] , b[par[v]]);
			}
			dp[par[v]] = max(dp[a[par[v]]] , dp[b[par[v]]] + 1);
			if(dp[par[v]] == h) break;
			v = par[v];
		}
		if(par[v] == 0){
			if(a[0] == -1){
				a[0] = v;
				dp[0] = 1;
			} else {
				if(dp[v] > dp[a[0]]){
					a[0] = v;
				}
				dp[0] = dp[a[0]];
			}
		}
		cout<<dp[0]<<' ';
	}
	cout<<'\n';
	return 0;
}