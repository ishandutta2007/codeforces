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

int step, k, all;
char ans[N + 10];
int first[N + 10], sz[N + 10], lst[N + 10], p[N + 10], used[N + 10];
int go[2 * N + 10], next[2 * N + 10];

inline void add(int a, int b){
	go[++k] = b;
	next[k] = first[a];
	first[a] = k;
}

void dfs(int a){
	lst[all++] = a;
	used[a] = step;
	sz[a] = 1;
	for(int i = first[a]; i > 0; i = next[i]){
		if(used[go[i]] != step){
			p[go[i]] = a;
			dfs(go[i]);
			sz[a] += sz[go[i]];
		}
	}
}

void solve(int a, char b){
	step++;
	all = 0;
	p[a] = -1;
	dfs(a);
	int res = inf, ver = -1;
	for(int i = 0; i < all; i++){
		int cur = all - sz[lst[i]];
		for(int j = first[lst[i]]; j > 0; j = next[j]){
			if(p[go[j]] == lst[i]){
				cur = max(cur, sz[go[j]]);
			}
		}
		if(cur < res){
			res = cur;
			ver = lst[i];
		}
	}
	ans[ver] = b;
	for(int i = first[ver]; i > 0; i = next[i]){
		int last = -1;
		for(int j = first[go[i]]; j > 0; j = next[j]){
			if(go[j] == ver){
				if(last == -1){
					first[go[i]] = next[j];
					break;
				}
				next[last] = next[j];
				break;
			}
			last = j;
		}
	}
	for(int i = first[ver]; i > 0; i = next[i]){
		solve(go[i], b + 1);
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	k = 0;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		add(a, b);
		add(b, a);
	}
	step = 0;
	solve(0, 'A');
	for(int i = 0; i < n; i++){
		printf("%c ", ans[i]);
	}
	puts("");
	return 0;
}