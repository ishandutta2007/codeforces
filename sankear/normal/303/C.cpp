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
const int N = 5000;
const int M = int(1e6);

int cnt, step, sz;
int a[N + 10], prev[N + 10], rank[N + 10], used[N + 10];
short x[N * N + 10], y[N * N + 10];
int next[N * N + 10];
int first[M + 10];

inline void add(int diff, int xx, int yy){
	x[++cnt] = xx;
	y[cnt] = yy;
	next[cnt] = first[diff];
	first[diff] = cnt;
}

int get(int a){
	if(used[a] != step){
		prev[a] = a;
		rank[a] = 1;
		used[a] = step;
	}
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

inline void add(int a, int b){
	a = get(a);
	b = get(b);
	if(a == b){
		return;
	}
	sz--;
	merge(a, b);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(x) + sizeof(y) + sizeof(next) + sizeof(first)) / 1024 / 1024 << endl;
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	cnt = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			add(a[j] - a[i], i, j);
		}
	}
	step = 0;
	for(int ans = 1; ; ans++){
		step++;
		sz = n;
		for(int i = ans; i <= a[n - 1] && sz >= n - k; i += ans){
			for(int j = first[i]; j > 0 && sz >= n - k; j = next[j]){
				add(x[j], y[j]);
			}
		}
		if(sz >= n - k){
			printf("%d\n", ans);
			break;
		}
	}
	return 0;
}