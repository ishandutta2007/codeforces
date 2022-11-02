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

int edges;
int a[10100], b[10100];
int pref_sz[10100], suff_sz[10100];
pii pref_edges[10100][505], suff_edges[10100][505];
bool used[555];
int prev[555], rank[555], first[555];
int go[2020], next[2020];

inline void add(int a, int b){
	go[++edges] = b;
	next[edges] = first[a];
	first[a] = edges;
}

void dfs(int a){
	used[a] = true;
	for(int i = first[a]; i > 0; i = next[i]){
		if(!used[go[i]]){
			dfs(go[i]);
		}
	}
}

int get(int a){
	if(prev[a] != a){
		prev[a] = get(prev[a]);
	}
	return prev[a];
}

inline void merge(int a, int b){
	if(rank[a] == rank[b]){
		prev[b] = a;
		rank[a]++;
		return;
	}
	if(rank[a] < rank[b]){
		prev[a] = b;
		return;
	}
	prev[b] = a;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(pref_edges) + sizeof(suff_edges)) / 1024 / 1024 << endl;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
	}
	for(int i = 0; i < n; i++){
		prev[i] = i;
		rank[i] = 1;
	}
	for(int i = 0; i < m; i++){
		if(i > 0){
			pref_sz[i] = pref_sz[i - 1];
			for(int j = 0; j < pref_sz[i]; j++){
				pref_edges[i][j] = pref_edges[i - 1][j];
			}
		}
		int pa = get(a[i]), pb = get(b[i]);
		if(pa == pb){
			continue;
		}
		merge(pa, pb);
		pref_edges[i][pref_sz[i]++] = mp(a[i], b[i]);
	}
	for(int i = 0; i < n; i++){
		prev[i] = i;
		rank[i] = 1;
	}
	for(int i = m - 1; i >= 0; i--){
		if(i + 1 < m){
			suff_sz[i] = suff_sz[i + 1];
			for(int j = 0; j < suff_sz[i]; j++){
				suff_edges[i][j] = suff_edges[i + 1][j];
			}
		}
		int pa = get(a[i]), pb = get(b[i]);
		if(pa == pb){
			continue;
		}
		merge(pa, pb);
		suff_edges[i][suff_sz[i]++] = mp(a[i], b[i]);
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		l -= 2;
		for(int j = 0; j < n; j++){
			used[j] = false;
			first[j] = 0;
		}
		edges = 0;
		if(l >= 0){
			for(int j = 0; j < pref_sz[l]; j++){
				add(pref_edges[l][j].fs, pref_edges[l][j].sc);
				add(pref_edges[l][j].sc, pref_edges[l][j].fs);
			}
		}
		if(r < m){
			for(int j = 0; j < suff_sz[r]; j++){
				add(suff_edges[r][j].fs, suff_edges[r][j].sc);
				add(suff_edges[r][j].sc, suff_edges[r][j].fs);
			}
		}
		int ans = 0;
		for(int j = 0; j < n; j++){
			if(!used[j]){
				ans++;
				dfs(j);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}