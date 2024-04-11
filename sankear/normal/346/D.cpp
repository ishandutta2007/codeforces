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
const int N = int(1e6);

int ans;
int d[N + 10], deg[N + 10];
vi g[N + 10];
vi lst, nlst;

inline void add(int v){
	if(d[v] <= ans){
		return;
	}
	d[v] = ans;
	nlst.pb(v);
	for(int i = 0; i < sz(g[v]); i++){
		deg[g[v][i]]--;
		if(deg[g[v][i]] == 0){
			add(g[v][i]);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		deg[a]++;
		g[b].pb(a);
	}
	for(int i = 0; i < n; i++){
		d[i] = inf;
	}
	int st, t;
	scanf("%d %d", &st, &t);
	st--;
	t--;
	ans = 0;
	add(t);
	while(sz(nlst) > 0){
		lst = nlst;
		nlst.clear();
		ans++;
		for(int i = 0; i < sz(lst); i++){
			for(int j = 0; j < sz(g[lst[i]]); j++){
				add(g[lst[i]][j]);
			}
		}
	}
	if(d[st] == inf){
		puts("-1");
		return 0;
	}
	printf("%d\n", d[st]);
	return 0;
}