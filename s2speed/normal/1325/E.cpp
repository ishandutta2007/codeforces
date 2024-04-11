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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 15 , MAXA = 1e6 + 15 , MAXP = 8e4 , md = 1e9 + 7 , inf = 1e18;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

unordered_map<ll , ll , custom_hash> c;
vector<ll> pr[MAXA] , p;
bitset<MAXA> gh , mark;

void prime(){
	p.push_back(1); c[1] = 0;
	gh.set();
	ll x = 1;
	for(ll i = 2 ; i < MAXA ; i++){
		if(gh[i]){
			pr[i].push_back(i);
			p.push_back(i);
			c[i] = x++;
			for(ll j = 2 * i ; j < MAXA ; j += i){
				gh[j] = false;
				pr[j].push_back(i);
			}
		}
	}
	return;
}

vector<ll> adj[MAXP] , v;
ll dis[MAXP] , par[MAXP];

ll BFS(ll u){
	memset(dis , 63 , sizeof(dis));
	memset(par , -1 , sizeof(par));
	v.clear();
	ll res = inf;
	dis[u] = 0;
	v.push_back(u);
	ll x = 0;
	while(x < v.size()){
		ll r = v[x];
		for(auto i : adj[r]){
			if(dis[i] > dis[r] + 1){
				dis[i] = dis[r] + 1;
				par[i] = r;
				v.push_back(i);
			} else if(i != par[r]){
				res = min(res , dis[i] + dis[r] + 1);
			}
		}
		x++;
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	ll n;
	cin>>n;
	bool two = false;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		for(auto i : pr[h]){
			ll o = 1ll * i * i;
			while(h % o == 0) h /= o;
		}
		if(h == 1){
			cout<<"1\n";
			return 0;
		}
		two |= mark[h];
		mark[h] = true;
		if(pr[h].size() == 1){
			ll v = 0 , u = c[pr[h][0]];
			adj[v].push_back(u); adj[u].push_back(v);
		} else {
			ll v = c[pr[h][0]] , u = c[pr[h][1]];
			adj[v].push_back(u); adj[u].push_back(v);
		}
	}
	if(two){
		cout<<"2\n";
		return 0;
	}
	ll ans = inf;
	for(ll i = 0 ; ; i++){
		if(p[i] > 1e3) break;
		ans = min(ans , BFS(i));
	}
	cout<<(ans == inf ? -1 : ans)<<'\n';
	return 0;
}

/*

*/