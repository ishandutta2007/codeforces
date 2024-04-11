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
const int N = int(1e5);
const int M = int(1e6);

int a, b;
int x[N + 10], d[M + 10], g[M + 10], fen[M + 10];

inline void update(int pos, int val){
	while(pos <= b - a){
		fen[pos] = min(fen[pos], val);
		pos = (pos | (pos + 1));
	}
}

inline int get(int pos){
	int res = inf;
	while(pos >= 0){
		res = min(res, fen[pos]);
		pos = (pos & (pos + 1)) - 1;
	}
	return res;
}

inline void gen(){
	freopen("input.txt", "w", stdout);
	int n = int(1e5);
	cout << n << endl;
	for(int i = 0; i < n; i++){
		cout << i + 2 << " ";
	}
	cout << endl;
	cout << int(1e9) - int(1e6) << " " << int(1e9) << endl;
	exit(0);
}

int main(){
	//gen();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	n = unique(x, x + n) - x;
	scanf("%d %d", &a, &b);
	swap(a, b);
	for(int i = a; i <= b; i++){
		d[i - a] = inf;
		g[i - a] = i;
	}
	for(int i = 0; i < n; i++){
		int k = (a + x[i] - 1) / x[i];
		while(ll(k) * x[i] <= b){
			g[k * x[i] - a] = max(g[k * x[i] - a], min((k + 1) * x[i] - 1, b));
			k++;
		}
	}
	for(int i = 0; i <= b - a; i++){
		fen[i] = inf;
	}
	d[b - a] = 0;
	update(b - a, d[b - a]);
	for(int i = b - 1; i >= a; i--){
		d[i - a] = d[i - a + 1] + 1;
		d[i - a] = min(d[i - a], get(g[i - a] - a) + 1);
		update(i - a, d[i - a]);
	}
	printf("%d\n", d[0]);
	return 0;
}