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

const ll MAXN = 1 << 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

ll dp[MAXN];
bitset<MAXN> cl;
bitset<40> adj[40];
bitset<20> v[20];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k , ans = 0;
	db s;
	cin>>n>>s; k = (n + 1) / 2;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			bool in;
			cin>>in;
			adj[i][j] = in;
		}
	}
	dp[0] = 0;
	for(int i = k ; i < n ; i++){
		for(int j = 0 ; j < k ; j++){
			v[i - k][j] = adj[i][j];
		}
	}
	ll lm = 1 << k;
	for(int i = 1 ; i < lm ; i++){
		ll h = __builtin_popcount(i) , o = 1 , u = 0;
		if(h == 2){
			int p = -1 , l = -1;
			for(int j = 0 ; j < k ; j++){
				if(i & o){
					if(p == -1){
						p = j;
					} else {
						l = j;
						break;
					}
				}
				o <<= 1;
			}
			dp[i] = 1 + adj[p][l];
			ans = max(ans , dp[i]);
			continue;
		}
		bool y = true;
		for(int j = 0 ; j < k ; j++){
			if(o & i){
				i -= o;
				u = max(u , dp[i]);
				y &= (dp[i] == h - 1);
				i += o;
			}
			o <<= 1;
		}
		dp[i] = u + y;
		ans = max(ans , dp[i]);
	}
	cl.set();
	int b = k;
	k = n - k;
	lm = 1 << k;
	for(int i = 1 ; i < lm ; i++){
		ll h = __builtin_popcount(i) , o = 1 , p = -1 , l = -1;
		for(int j = 0 ; j < k ; j++){
			if(i & o){
				if(p == -1){
					p = j;
				} else {
					l = j;
				}
				ll y = i - o;
				cl[i] = cl[i] & cl[y];
			}
			o <<= 1;
		}
		if(h == 2){
			cl[i] = adj[p + b][l + b];
		}
		if(!cl[i]) continue;
		o = 1;
		bitset<20> tmp;
		tmp.set();
		for(int j = 0 ; j < k ; j++){
			if(o & i){
				tmp &= v[j];
			}
			o <<= 1;
		}
		o = 1;
		int q = 0;
		for(int j = 0 ; j < b ; j++){
			if(tmp[j]){
				q += o;
			}
			o <<= 1;
		}
		ans = max(ans , dp[q] + h);
	}
	db z = ans - 1 , e = s * s / 2;
	e *= z;
	z++;
	e /= z;
	printf("%.10Lf\n" , e);
	return 0;
}

/*

*/