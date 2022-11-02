#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>
#include <stack>

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
#define link _link
#define hash _hash
#define rank _rank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int M = 20;
const int N = int(1e5) + 100;

int sz[M];
int a[M][N], s[M][N];
bool bad[(1 << M)];

inline int get_sum(int *s, int l, int r){
	if(l > r){
		return 0;
	}
	return s[r] - s[l - 1];
}

int main(){
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	for(int i = 0; i < m; i++){
		scanf("%d", &sz[i]);
		for(int j = 0; j < sz[i]; j++){
			scanf("%d", &a[i][j]);
		}
		sort(a[i], a[i] + sz[i]);
		int ptr = 0;
		for(int j = 1; j <= n; j++){
			if(ptr < sz[i] && a[i][ptr] == j){
				ptr++;
			}
			s[i][j] = ptr;
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < sz[i]; j++){
			if(a[i][j] <= d){
				continue;
			}
			int mask = 0;
			for(int z = 0; z < m; z++){
				if(get_sum(s[z], max(a[i][j] - d, 1), a[i][j] - 1) == 0){
					mask |= (1 << z);
				}
			}
			bad[mask] = true;
		}
	}
	for(int i = (1 << m) - 1; i > 0; i--){
		if(bad[i]){
			for(int j = 0; j < m; j++){
				if((i & (1 << j)) != 0){
					bad[i ^ (1 << j)] = true;
				}
			}
		}
	}
	int ans = m;
	for(int i = 1; i < (1 << m); i++){
		if(!bad[i]){
			int res = 0, max_a = -inf;
			for(int j = 0; j < m; j++){
				if((i & (1 << j)) != 0){
					res++;
					max_a = max(max_a, a[j][sz[j] - 1]);
				}
			}
			if(max_a + d >= n + 1){
				ans = min(ans, res);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}