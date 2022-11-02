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
const int N = 100;

int n;
bool used[N + 10][2];
bool use[N + 10][N + 10][3][3];
int d[N + 10][N + 10][3][3];

inline int calc(int l, int r, int sl, int sr){
	if(l > r){
		return 0;
	}
	if(use[l][r][sl][sr]){
		return d[l][r][sl][sr];
	}
	use[l][r][sl][sr] = true;
	vi vals;
	for(int i = l; i <= r; i++){
		for(int j = 0; j < 2; j++){
			if(used[i][j] || used[i][1 - j]){
				continue;
			}
			if(i > 0 && used[i - 1][1 - j]){
				continue;
			}
			if(i + 1 < n && used[i + 1][1 - j]){
				continue;
			}
			if(i == l && sl == 2 - j){
				continue;
			}
			if(i == r && sr == 2 - j){
				continue;
			}
			vals.pb(calc(l, i - 1, sl, j + 1) ^ calc(i + 1, r, j + 1, sr));
		}
	}
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	if(sz(vals) == 0 || vals[0] != 0){
		return d[l][r][sl][sr] = 0;
	}
	for(int i = 0; i < sz(vals); i++){
		if(i == sz(vals) - 1 || vals[i + 1] != vals[i] + 1){
			return d[l][r][sl][sr] = vals[i] + 1;
		}
	}
	assert(false);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		used[x][y] = true;
	}
	if(calc(0, n - 1, 0, 0) == 0){
		puts("LOSE");
		return 0;
	}
	puts("WIN");
	return 0;
}