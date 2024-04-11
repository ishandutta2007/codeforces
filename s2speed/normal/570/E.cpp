#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 5e2 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

ll n , m;
ll dp[MAXN][MAXN] , pd[MAXN][MAXN];
char s[MAXN][MAXN];

pll find_pos(ll h , ll k){
	ll i , j;
	i = min(n - 1 , h);
	j = max(0ll , h - n + 1);
	i -= k;
	j += k;
	if(i < 0 || j >= m) return {-1 , -1};
	return {i , j};
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	if(n > m){
		for(int j = 0 ; j < n ; j++){
			for(int i = 0 ; i < m ; i++){
				cin>>s[i][j];
			}
		}
		swap(n , m);
	} else {
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin>>s[i][j];
			}
		}
	}
//	pll y = find_pos(5 , 0);
//	cout<<y.first<<' '<<y.second<<'\n';
	memset(dp , 0 , sizeof(dp));
	memset(pd , 0 , sizeof(pd));
	ll q = (n + m) / 2;
	if((n + m) % 2 == 0){
		ll lm = min(n , m);
		for(int i = 0 ; i < lm ; i++){
			pd[i][i] = 1;
		}
	} else {
		ll ml = min(n , m);
		for(int i = 0 ; i < ml ; i++){
			pll p = find_pos(q - 1 , i) , o = find_pos(q , i) , h = find_pos(q , i - 1);
			if(p.first == -1) break;
			if(o.first != -1){
				pd[i][i] = (s[p.first][p.second] == s[o.first][o.second]);
			}
			if(h.first != -1){
				pd[i][i - 1] = (s[p.first][p.second] == s[h.first][h.second]);
			}
		}
	}
	ll lm = (n + m + 1) / 2 , w = q - 2 , v = q + (n + m) % 2;
	for(int k = 1 + (n + m) % 2 ; k < lm ; k++ , w-- , v++){
		ll ml = min(n , m);
		for(int i = 0 ; i < ml ; i++){
			pll h = find_pos(w , i);
			if(h.first == -1) break;
			for(int j = 0 ; j < ml ; j++){
				pll o = find_pos(v , j);
				if(o.first == -1){
					break;
				}
				if(s[h.first][h.second] != s[o.first][o.second]){
					continue;
				}
				ll r = pd[i][j] + pd[i][j + 1];
				if(w >= n - 1){
					if(i > 0){
						r += pd[i - 1][j] + pd[i - 1][j + 1];
					}
				} else {
					r += pd[i + 1][j] + pd[i + 1][j + 1];
				}
				dp[i][j] = r % md;
			}
		}
		memcpy(pd , dp , sizeof(dp));
		memset(dp , 0 , sizeof(dp));
	}
	cout<<pd[0][0]<<'\n';
	return 0;
}

/*

*/