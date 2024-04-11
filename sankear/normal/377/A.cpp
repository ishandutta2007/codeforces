#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define fs first
#define sc second
#define next _next
#define prev _prev
#define hash _hash
#define link _link
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 555;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, k;
bool used[N][N];
char a[N][N];

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y){
	used[x][y] = true;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(good(nx, ny) && a[nx][ny] == '.' && !used[nx][ny]){
			dfs(nx, ny);
		}
	}
	if(k > 0){
		a[x][y] = 'X';
		k--;
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	gets(a[0]);
	for(int i = 0; i < n; i++){
		gets(a[i]);
	}
	bool fl = false;
	for(int i = 0; i < n && !fl; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '.'){
				dfs(i, j);
				fl = true;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		puts(a[i]);
	}
	return 0;
}