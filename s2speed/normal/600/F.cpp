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

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll mt[maxn][maxn][2] , cl[maxn][maxn] , d[maxn][2];
vector<pll> ed;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(mt , -1 , sizeof(mt));
	memset(d , 0 , sizeof(d));
	ll a , b , m;
	cin>>a>>b>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		ed.push_back({v , u});
		d[v][0]++; d[u][1]++;
	}
	ll t = 0;
	for(ll i = 0 ; i < a ; i++){
		t = max(t , d[i][0]);
	}
	for(ll i = 0 ; i < b ; i++){
		t = max(t , d[i][1]);
	}
	for(auto p : ed){
		ll v = p.first , u = p.second;
		bool f = false;
		for(ll j = 0 ; j < t ; j++){
			if(mt[v][j][0] == -1 && mt[u][j][1] == -1){
				mt[v][j][0] = u; mt[u][j][1] = v;
				f = true;
				break;
			}
		}
		if(f) continue;
		ll c[2];
		bool o = false;
		for(ll j = 0 ; j < t ; j++){
			if(mt[v][j][0] != -1 && mt[u][j][1] == -1){
				c[0] = j;
			}
			if(mt[v][j][0] == -1){
				c[1] = j;
			}
		}
		ll h = v;
		while(h != -1){
			ll g = mt[h][c[o]][o];
			swap(mt[h][c[0]][o] , mt[h][c[1]][o]);
			h = g;
			o ^= 1;
		}
		mt[v][c[0]][0] = u; mt[u][c[0]][1] = v;
	}
	for(ll i = 0 ; i < a ; i++){
		for(ll j = 0 ; j < t ; j++){
			if(mt[i][j][0] == -1) continue;
			cl[i][mt[i][j][0]] = j;
		}
	}
	cout<<t<<'\n';
	for(auto p : ed){
		ll v = p.first , u = p.second;
		cout<<cl[v][u] + 1<<' ';
	}
	cout<<'\n';
	return 0;
}

/*
3 2 4
3 2
1 1
2 2
2 1
*/