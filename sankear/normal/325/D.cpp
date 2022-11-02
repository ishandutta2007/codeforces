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
const int N = 3000;

int step, edges;
int prev[2 * N * N + 10], rank[2 * N * N + 10];
bool used[N + 10][2 * N + 10];
int use[2 * N * N + 10], num[2 * N * N + 10];
int a[N + 10], b[N + 10];

inline void add(int _a, int _b){
	a[edges] = _a;
	b[edges++] = _b;
	a[edges] = _b;
	b[edges++] = _a;
}

void dfs(int v){
	use[v] = step;
	for(int i = 0; i < edges; i++){
		if(a[i] == v && use[b[i]] != step){
			dfs(b[i]);
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
	a = get(a);
	b = get(b);
	if(a == b){
		return;
	}
	if(rank[a] < rank[b]){
		swap(a, b);
	}
	prev[b] = a;
	if(rank[a] == rank[b]){
		rank[a]++;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2 * m; j++){
			prev[i * 2 * m + j] = i * 2 * m + j;
			rank[i * 2 * m + j] = 1;
		}
	}
	int ans = 0;
	step = 0;
	for(int i = 0; i < k; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		used[x][y] = used[x][y + m] = true;
		int sz = 0;
		num[x * 2 * m + y] = sz++;
		num[x * 2 * m + y + m] = sz++;
		step++;
		edges = 0;
		for(int j = -1; j <= 1; j++){
			for(int z = -1; z <= 1; z++){
				if(j == 0 && z == 0){
					continue;
				}
				int nx = x + j, ny = y + z;
				if(nx < 0 || nx >= n){
					continue;
				}
				if(ny < 0){
					ny += 2 * m;
				}
				if(ny >= 2 * m){
					ny -= 2 * m;
				}
				if(used[nx][ny]){
					int p = get(nx * 2 * m + ny);
					if(use[p] != step){
						use[p] = step;
						num[p] = sz++;
						add(num[x * 2 * m + y], num[p]);
					}
					else{
						add(num[x * 2 * m + y], num[p]);
					}
				}
			}
		}
		for(int j = -1; j <= 1; j++){
			for(int z = -1; z <= 1; z++){
				if(j == 0 && z == 0){
					continue;
				}
				int nx = x + j, ny = y + m + z;
				if(nx < 0 || nx >= n){
					continue;
				}
				if(ny < 0){
					ny += 2 * m;
				}
				if(ny >= 2 * m){
					ny -= 2 * m;
				}
				if(used[nx][ny]){
					int p = get(nx * 2 * m + ny);
					if(use[p] != step){
						use[p] = step;
						num[p] = sz++;
						add(num[x * 2 * m + y + m], num[p]);
					}
					else{
						add(num[x * 2 * m + y + m], num[p]);
					}
				}
			}
		}
		step++;
		dfs(num[x * 2 * m + y]);
		if(use[num[x * 2 * m + y + m]] == step){
			used[x][y + m] = used[x][y] = false;
			continue;
		}
		ans++;
		for(int j = -1; j <= 1; j++){
			for(int z = -1; z <= 1; z++){
				if(j == 0 && z == 0){
					continue;
				}
				int nx = x + j, ny = y + z;
				if(nx < 0 || nx >= n){
					continue;
				}
				if(ny < 0){
					ny += 2 * m;
				}
				if(ny >= 2 * m){
					ny -= 2 * m;
				}
				if(used[nx][ny]){
					merge(x * 2 * m + y, nx * 2 * m + ny);
				}
			}
		}
		for(int j = -1; j <= 1; j++){
			for(int z = -1; z <= 1; z++){
				if(j == 0 && z == 0){
					continue;
				}
				int nx = x + j, ny = y + m + z;
				if(nx < 0 || nx >= n){
					continue;
				}
				if(ny < 0){
					ny += 2 * m;
				}
				if(ny >= 2 * m){
					ny -= 2 * m;
				}
				if(used[nx][ny]){
					merge(x * 2 * m + y + m, nx * 2 * m + ny);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}