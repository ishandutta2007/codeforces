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
const int MOD = int(1e9) + 7;
const int N = 3000;

int n, m;
char a[N + 10][N + 10];
int d[N + 10][N + 10];

inline void norm(int &a){
	while(a >= MOD){
		a -= MOD;
	}
}

inline int calc(int x1, int y1, int x2, int y2){
	if(a[x1][y1] == '#' || a[x2][y2] == '#'){
		return 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			d[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == x1 && j == y1){
				d[i][j] = 1;
				continue;
			}
			if(a[i][j] == '#'){
				continue;
			}
			if(i > 0){
				d[i][j] += d[i - 1][j];
			}
			if(j > 0){
				d[i][j] += d[i][j - 1];
			}
			norm(d[i][j]);
		}
	}
	return d[x2][y2];
}

int main(){
	scanf("%d %d", &n, &m);
	gets(a[0]);
	for(int i = 0; i < n; i++){
		gets(a[i]);
	}
	int a = calc(0, 1, n - 2, m - 1), b = calc(0, 1, n - 1, m - 2);
	int c = calc(1, 0, n - 2, m - 1), d = calc(1, 0, n - 1, m - 2);
	int ans = (ll(a) * d - ll(b) * c) % MOD;
	ans = (ans + MOD) % MOD;
	printf("%d\n", ans);
	return 0;
}