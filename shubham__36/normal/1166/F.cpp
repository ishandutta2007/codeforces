#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF LLONG_MAX

#define all(c) (c).begin(), (c).end()
struct DSU {
	vector<int> rep;
	vector<set<int>> edges;
	
	void clear() {
		iota(all(rep), 0);
	}
	
	DSU(int n=0): rep(n+1), edges(n+1) {
		clear();
	}
	
	int find(int a) {
		return rep[a] == a ? a : rep[a] = find(rep[a]);
	}
	
	void merge(int a, int b) {
		if(a == 0 or b == 0) return;
		if(edges[a = find(a)].size() < edges[b = find(b)].size())
			swap(a, b);
		if(a == b) return;
		for(auto x:edges[b])
			edges[a].insert(x);
		rep[b] = a;
	}
	
	void add_edge(int a, int b) {
		edges[find(a)].insert(b), edges[find(b)].insert(a);
	}
};

const ll LIM = 1e5+5;
map<ll,ll> mmap[LIM];

void solve(){
	ll n,m,c,q;
	cin >> n >> m >> c >> q;
	DSU D = DSU(n); 
	// D.reset(n);
	forn(i,m){
		ll x,y,z;
		cin >> x >> y >> z;
		D.merge(mmap[x][z],y);
		D.merge(mmap[y][z],x);
		mmap[x][z]=y;
		mmap[y][z]=x;
		D.add_edge(x,y);
	}
	forn(i,q){
		char ch;
		cin >> ch;
		if(ch=='?'){
			ll x,y;
			cin >> x >> y;
			ll rx = D.find(x);
			ll ry = D.find(y);
			bool bo = (rx==ry || D.edges[rx].find(y)!=D.edges[rx].end());
			if(bo) cout << "Yes" << ln;
			else cout << "No" << ln;
		}
		else{
			ll x,y,z;
			cin >> x >> y >> z;
			D.merge(mmap[x][z],y);
			D.merge(mmap[y][z],x);
			mmap[x][z]=y;
			mmap[y][z]=x;
			D.add_edge(x,y);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve();
    return 0;
}