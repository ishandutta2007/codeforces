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
const int N = 1000;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

char a[N + 10][N + 10];
int d[N + 10][N + 10];
int q[2 * N * N + 10];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	gets(a[0]);
	for(int i = 0; i < n; i++){
		gets(a[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			d[i][j] = inf;
		}
	}
	int l = 0, r = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'E'){
				d[i][j] = 0;
				q[r++] = i;
				q[r++] = j;
			}
		}
	}
	while(l < r){
		int x = q[l++], y = q[l++];
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m | a[nx][ny] == 'T'){
				continue;
			}
			if(d[nx][ny] > d[x][y] + 1){
				d[nx][ny] = d[x][y] + 1;
				q[r++] = nx;
				q[r++] = ny;
			}
		}
	}
	int dist = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'S'){
				dist = d[i][j];
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] >= '0' && a[i][j] <= '9' && d[i][j] <= dist){
				ans += a[i][j] - '0';
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}