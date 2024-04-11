#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

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

const ll MAXN = 1e5 + 15 , MAXV = 7e3 + 15 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

vector<int> adj[MAXV];
bitset<MAXV> gh , sqfr;
vector<int> sf;

void prime(){
	gh.set(); gh[0] = false; gh[1] = false;
	sqfr.set(); sqfr[0] = false; sf.push_back(1);
	for(int i = 2 ; i < MAXV ; i++){
		if(gh[i]){
			int k = i * i;
			for(int j = k ; j < MAXV ; j += i){
				gh[j] = false;
			}
			for(int j = k ; j < MAXV ; j += k){
				sqfr[j] = false;
			}
		}
		if(sqfr[i]){
			sf.push_back(i);
		}
	}
	return;
}

bitset<MAXV> a[MAXN] , c[MAXV];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	int n , q;
	cin>>n>>q;
	for(int i = 1 ; i < MAXV ; i++){
		for(int j = i ; j < MAXV ; j += i){
			adj[j].push_back(i);
		}
	}
	for(ll i = 1 ; i < MAXV ; i++){
		for(auto j : sf){
			if(j * i >= MAXV) break;
			c[i][j * i] = true;
		}
	}
	while(q--){
		int t , x , y , z , v;
		cin>>t;
		if(t == 1){
			cin>>x>>v;
			x--;
			a[x].reset();
			for(auto j : adj[v]){
				a[x][j] = true;
			}
		}
		if(t == 2){
			cin>>x>>y>>z; x--; y--; z--;
			a[x] = a[y] ^ a[z];
		}
		if(t == 3){
			cin>>x>>y>>z; x--; y--; z--;
			a[x] = a[y] & a[z];
		}
		if(t == 4){
			cin>>x>>v; x--;
			bitset<MAXV> tmp = a[x] & c[v];
			cout<<tmp.count() % 2;
		}
	}
	cout<<'\n';
	return 0;
}

/*

*/