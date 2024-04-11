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

const ll maxn = 15e2 + 16 , md = 1e9 + 7;
ll inf;

int ds[maxn * maxn];
char a[maxn][maxn];
pii mark[maxn * maxn] , cur = {0 , 0};
vector<piii> adj[maxn * maxn];
bool ans = false;

int dsu(int v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(int v , int u){
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	ds[u] = v;
	return;
}

void DFS(int r , pii w){
	cur.first += w.first; cur.second += w.second;
	if(mark[r].first != inf){
		ans = true;
		return;
	}
	mark[r] = cur;
	for(auto q : adj[r]){
		int i = q.first;
		pii p = q.second;
		if(mark[i] == mp(cur.first + p.first , cur.second + p.second)) continue;
		DFS(i , p);
		if(ans) return;
	}
	cur.first -= w.first; cur.second -= w.second;
	return;
}


int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(mark , 63 , sizeof(mark));
	inf = mark[0].first;
	int n , m , s;
	pll z = {0 , 0};
	cin>>n>>m;
	iota(ds , ds + n * m , 0);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>a[i][j];
			if(a[i][j] == 'S') s = i * m + j;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(a[i][j] == '#') continue;
			int v = i * m + j;
			if(i < n - 1){
				if(a[i + 1][j] != '#'){
					merge(v , v + m);
				}
			}
			if(j < m - 1){
				if(a[i][j + 1] != '#'){
					merge(v , v + 1);
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i][0] == '#' || a[i][m - 1] == '#') continue;
		adj[dsu(i * m)].push_back({dsu(i * m + m - 1) , {1 , 0}}); adj[dsu(i * m + m - 1)].push_back({dsu(i * m) , {-1 , 0}});
	}
	for(int j = 0 ; j < m ; j++){
		if(a[0][j] == '#' || a[n - 1][j] == '#') continue;
		adj[dsu(j)].push_back({dsu(n * m - m + j) , {0 , 1}}); adj[dsu(n * m - m + j)].push_back({dsu(j) , {0 , -1}});
	}
	DFS(dsu(s) , z);
	cout<<(ans ? "Yes\n" : "No\n");
	return 0;
}

/*
6 6
##.#S#
.#.#..
.#.###
.#...#
.###.#
...#.#
12 12
######S#.###
######.#.###
.....#.#....
####.#.#####
...#.#......
##.#.#######
##.#.......#
##.#######.#
##.......#.#
########.#.#
.......#.#..
######.#.###
*/