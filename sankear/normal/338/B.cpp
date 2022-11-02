#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5);

int ans, d;
bool used[N + 10], good[N + 10];
int dist[N + 10];
vi g[N + 10];

void dfs1(int v){
	used[v] = true;
	dist[v] = -inf;
	if(good[v]){
		dist[v] = 0;
	}
	for(int i = 0; i < sz(g[v]); i++){
		if(!used[g[v][i]]){
			dfs1(g[v][i]);
			dist[v] = max(dist[v], dist[g[v][i]] + 1);
		}
	}
}

void dfs2(int v, int max_dist){
	//cerr << v << " " << max_dist << " " << max(max_dist, dist[v]) << endl;
	used[v] = true;
	if(max(max_dist, dist[v]) <= d){
		ans++;
	}
	vi sons;
	for(int i = 0; i < sz(g[v]); i++){
		if(!used[g[v][i]]){
			sons.pb(g[v][i]);
		}
	}
	vi pref(sz(sons));
	for(int i = 0; i < sz(sons); i++){
		pref[i] = max((i > 0 ? pref[i - 1] : -inf), dist[sons[i]] + 2);
	}
	vi suff(sz(sons));
	for(int i = sz(sons) - 1; i >= 0; i--){
		suff[i] = max((i + 1 < sz(sons) ? suff[i + 1] : -inf), dist[sons[i]] + 2);
	}
	for(int i = 0; i < sz(sons); i++){
		int new_dist = max_dist + 1;
		if(i > 0){
			new_dist = max(new_dist, pref[i - 1]);
		}
		if(i + 1 < sz(sons)){
			new_dist = max(new_dist, suff[i + 1]);
		}
		if(good[sons[i]]){
			new_dist = max(new_dist, 0);
		}
		dfs2(sons[i], new_dist);
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d %d", &n, &m, &d);
	for(int i = 0; i < m; i++){
		int cur;
		scanf("%d", &cur);
		cur--;
		good[cur] = true;
	}
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs1(0);
	for(int i = 0; i < n; i++){
		used[i] = false;
	}
	ans = 0;
	dfs2(0, (good[0] ? 0 : -inf));
	printf("%d\n", ans);
	return 0;
}