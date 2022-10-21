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

const ll maxn = 1e5 + 16 , maxsq = 350 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , b[maxn] , c[maxn] , vs[maxn] , ind[maxn];
int z[maxn][maxsq];
vector<ll> v[maxn] , u;
bitset<maxn> ch[maxsq];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(b , 0 , sizeof(b));
	memset(c , 0 , sizeof(c));
	memset(ind , -1 , sizeof(ind));
	ll n , m , q , sq , sum = 0;
	cin>>m>>n>>q;
	for(ll i = 0 ; i < m ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>vs[i];
		sum += vs[i];
		v[i].resize(vs[i]);
		for(ll j = 0 ; j < vs[i] ; j++){
			cin>>v[i][j]; v[i][j]--;
		}
	}
	sq = min(340ll , sum);
	for(ll i = 0 ; i < n ; i++){
		if(vs[i] <= sq) continue;
		ind[i] = sze(u);
		u.push_back(i);
		for(auto j : v[i]){
			ch[ind[i]][j] = true;
		}
	}
	ll us = sze(u);
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < us ; j++){
			ll h = 0;
			for(auto k : v[i]){
				h += ch[j][k];
			}
			z[i][j] = h;
		}
		if(ind[i] == -1) continue;
		for(auto k : v[i]){
			c[i] += a[k];
		}
	}
	for(ll e = 0 ; e < q ; e++){
		char ct;
		cin>>ct;
		if(ct == '?'){
			ll i , res = 0;
			cin>>i; i--;
			if(ind[i] != -1){
				res = c[i];
			} else {
				for(auto k : v[i]){
					res += a[k];
				}
			}
			for(ll j = 0 ; j < us ; j++){
				res += z[i][j] * b[j];
			}
			cout<<res<<'\n';
		} else {
			ll i , w;
			cin>>i>>w; i--;
			if(ind[i] != -1){
				b[ind[i]] += w;
			} else {
				for(auto k : v[i]){
					a[k] += w;
				}
				for(ll j = 0 ; j < us ; j++){
					c[u[j]] += z[i][j] * w;
				}
			}
		}
	}
	return 0;
}