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
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , maxsq = 500 , md = 1e9 + 7 , inf = 2e16;

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

int ps[maxn] , c[maxsq][maxsq] , a[maxn] , b[maxn] , l[maxn];

/*
3 4
10 15
12 10
1 1
1 3
1 1
2 1
2 3
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , 0 , sizeof(c));
	memset(ps , 0 , sizeof(ps));
	int n , q , sq;
	cin>>n>>q; sq = min(q , 495);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]>>b[i];
	}
	int cur = 0;
	for(int i = 0 ; i < q ; i++){
		int k , t;
		cin>>t>>k; k--;
		if(t == 1){
			if(a[k] + b[k] >= sq){
				for(int h = i + a[k] ; h < q ;){
					ps[h]++;
					h += b[k];
					if(h >= q) break;
					ps[h]--;
					h += a[k];
				}
			} else {
				int o = a[k] + b[k];
				for(int j = (i + a[k]) % o , cnt = 0 ; cnt < b[k] ; j++ , j %= o , cnt++){
					c[o][j]++;
				}
			}
			l[k] = i;
		} else {
			if(a[k] + b[k] >= sq){
				bool f = true;
				for(int h = l[k] + a[k] ; h < q ;){
					if(f && h >= i){
						f = false;
					}
					ps[h]--;
					h += b[k];
					if(f && h >= i){
						f = false;
						cur--;
					}
					if(h >= q) break;
					ps[h]++;
					h += a[k];
				}
			} else {
				int o = a[k] + b[k];
				for(int j = (l[k] + a[k]) % o , cnt = 0 ; cnt < b[k] ; j++ , j %= o , cnt++){
					c[o][j]--;
				}
			}
		}
		cur += ps[i];
		int res = cur;
		for(int j = 1 ; j < sq ; j++){
			res += c[j][i % j];
		}
		cout<<res<<'\n';
	}
	return 0;
}