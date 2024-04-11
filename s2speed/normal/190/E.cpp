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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll MAXN = 5e5 + 20 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement
// di = 2m

unordered_set<int> s[MAXN];
vector<int> adj[MAXN] , a , b , ans[MAXN];
vector<pii> ed;
int d[MAXN] , cnt = 0;
bitset<MAXN> mark;

void BFS(int r){
	mark[r] = true;
	ans[cnt].push_back(r);
	int x = 0;
	while(x < ans[cnt].size()){
		int v = ans[cnt][x];
		for(auto i : adj[v]){
			if(mark[i]) continue;
			mark[i] = true;
			ans[cnt].push_back(i);
		}
		x++;
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(d , 0 , sizeof(d));
	int n , m , dl = MAXN , ind = -1 , v , u;
	scanf("%d%d" , &n , &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d" , &v , &u); v--; u--;
		ed.push_back({v , u});
		d[v]++; d[u]++;
		s[v].insert(u); s[u].insert(v);
	}
	for(int i = 0 ; i < n ; i++){
		if(dl > d[i]){
			dl = d[i];
			ind = i;
		}
	}
	mark[ind] = true;
	for(int i = 0 ; i < m ; i++){
		v = ed[i].first; u = ed[i].second;
		if(v != ind) swap(v , u);
		if(v == ind){
			mark[u] = true;
			a.push_back(u);
		}
	}
	for(int i = 0 ; i < dl ; i++){
		v = a[i];
		for(int j = i + 1 ; j < dl ; j++){
			u = a[j];
			if(s[v].count(u) == 0){
				adj[v].push_back(u); adj[u].push_back(v);
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		b.push_back(i);
	}
	int as = a.size() , bs = b.size();
	for(int i = 0 ; i < bs ; i++){
		adj[ind].push_back(b[i]); adj[b[i]].push_back(ind);
	}
	for(int i = 0 ; i < as ; i++){
		v = a[i];
		for(int j = 0 ; j < bs ; j++){
			u = b[j];
			if(s[v].count(u) == 0){
				adj[v].push_back(u); adj[u].push_back(v);
			}
		}
	}
	mark.reset();
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		BFS(i);
		cnt++;
	}
	printf("%d\n" , cnt);
	for(int i = 0 ; i < cnt ; i++){
		printf("%d " , ans[i].size());
		for(auto j : ans[i]){
			printf("%d " , j + 1);
		}
		printf("\n");
	}
	return 0;
}

/*

*/