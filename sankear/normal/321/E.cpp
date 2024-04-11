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
const int N = 4000;
const int K = 800;
const int LEN = int(1e4);

int a[N + 10][N + 10], sum[N + 10][N + 10], cost[N + 10][N + 10];
int d[N + 10][K + 10], ptr[N + 10][K + 10];
char s[LEN + 10];

inline int get_sum(int x1, int y1, int x2, int y2){
	int res = sum[x2][y2];
	if(x1 > 0){
		res -= sum[x1 - 1][y2];
	}
	if(y1 > 0){
		res -= sum[x2][y1 - 1];
	}
	if(x1 > 0 && y1 > 0){
		res += sum[x1 - 1][y1 - 1];
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(a) + sizeof(sum) + sizeof(d) + sizeof(ptr) + sizeof(cost)) / 1024 / 1024 << endl;
	int n, k;
	scanf("%d %d", &n, &k);
	gets(s);
	for(int i = 0; i < n; i++){
		gets(s);
		int len = strlen(s), ptr = 0;
		for(int j = 0; j < len; j++){
			if(s[j] >= '0' && s[j] <= '9'){
				a[i][ptr++] = s[j] - '0';
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sum[i][j] = a[i][j];
			if(i > 0){
				sum[i][j] += sum[i - 1][j];
			}
			if(j > 0){
				sum[i][j] += sum[i][j - 1];
			}
			if(i > 0 && j > 0){
				sum[i][j] -= sum[i - 1][j - 1];
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			cost[i][j] = get_sum(i, i, j, j) / 2;
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			d[i][j] = inf;
		}
	}
	d[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = min(i, k); j >= 1; j--){
			if(j == 1){
				d[i][j] = cost[0][i - 1];
			}
			else{
				int lg = ptr[i - 1][j], rg = (j < min(i, k) ? ptr[i][j + 1] : i - 1);
				assert(lg <= rg);
				for(int z = lg; z <= rg; z++){
					if(d[z][j - 1] + cost[z][i - 1] < d[i][j]){
						d[i][j] = d[z][j - 1] + cost[z][i - 1];
						ptr[i][j] = z;
					}
				}
			}
		}
	}
	printf("%d\n", d[n][k]);
	return 0;
}