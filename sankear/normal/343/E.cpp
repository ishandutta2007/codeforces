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
#define len(s) int((s).size())
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
typedef long long int64;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 200;
const int M = 1000;

struct edge{
	int go, c, f;
};

int n, s, t, sz;
bool used[N + 10];
int first[N + 10], ptr[N + 10], d[N + 10], prev[N + 10], q[N + 10], lst[N + 10];
edge e[4 * M + 10];
int next[4 * M + 10];
int g[N + 10][N + 10];

inline void add(int a, int b, int c){
	e[++sz].go = b;
	e[sz].c = c;
	e[sz].f = 0;
	next[sz] = first[a];
	first[a] = sz;
	e[++sz].go = a;
	e[sz].c = e[sz].f = 0;
	next[sz] = first[b];
	first[b] = sz;
}

int dfs(int v, int f){
	if(v == t){
		return f;
	}
	while(ptr[v] > 0){
		if(e[ptr[v]].c - e[ptr[v]].f == 0 || d[e[ptr[v]].go] != d[v] + 1){
			ptr[v] = next[ptr[v]];
			continue;
		}
		int nf = dfs(e[ptr[v]].go, min(f, e[ptr[v]].c - e[ptr[v]].f));
		if(nf > 0){
			e[ptr[v]].f += nf;
			if(ptr[v] % 2 == 0){
				e[ptr[v] - 1].f -= nf;
			}
			else{
				e[ptr[v] + 1].f -= nf;
			}
			return nf;
		}
		ptr[v] = next[ptr[v]];
	}
	return 0;
}

inline int get_flow(int a, int b){
	for(int i = 0; i < n; i++){
		for(int j = first[i]; j > 0; j = next[j]){
			e[j].f = 0;
		}
	}
	s = a;
	t = b;
	int flow = 0;
	while(true){
		for(int i = 0; i < n; i++){
			d[i] = inf;
		}
		d[s] = 0;
		int l = 0, r = 1;
		q[0] = s;
		while(l < r){
			int cur = q[l++];
			for(int i = first[cur]; i > 0; i = next[i]){
				if(e[i].c - e[i].f > 0 && d[e[i].go] > d[cur] + 1){
					d[e[i].go] = d[cur] + 1;
					q[r++] = e[i].go;
				}
			}
		}
		if(d[t] == inf){
			break;
		}
		for(int i = 0; i < n; i++){
			ptr[i] = first[i];
		}
		while(true){
			int add = dfs(s, inf);
			if(add == 0){
				break;
			}
			flow += add;
		}
	}
	return flow;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf("%d %d", &n, &m);
	sz = 0;
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		add(a, b, c);
		add(b, a, c);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			g[i][j] = 0;
		}
		g[i][i] = inf;
	}
	for(int i = 1; i < n; i++){
		g[i][prev[i]] = g[prev[i]][i] = get_flow(i, prev[i]);
		for(int j = i + 1; j < n; j++){
			if(d[j] != inf && prev[j] == prev[i]){
				prev[j] = i;
			} 
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int z = 0; z < n; z++){
				g[j][z] = max(g[j][z], min(g[j][i], g[i][z]));
			}
		}
	}
	int ans = 0;
	used[0] = true;
	lst[0] = 0;
	for(int i = 1; i < n; i++){
		int best = -1;
		for(int j = 0; j < n; j++){
			if(!used[j] && (best == -1 || g[lst[i - 1]][j] > g[lst[i - 1]][best])){
				best = j;
			}
		}
		used[best] = true;
		lst[i] = best;
		ans += g[lst[i - 1]][lst[i]];
	}
	printf("%d\n", ans);
	for(int i = 0; i < n; i++){
		printf("%d ", lst[i] + 1);
	}
	puts("");
	return 0;
}