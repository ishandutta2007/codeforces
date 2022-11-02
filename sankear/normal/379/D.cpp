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

const ll inf = ll(1e10);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int K = 55;
const int N = 111;
const char ch[] = {'A', 'C', 'B'};

struct elem {
	int first, last;
	ll b[2];
	ll a[2][2];
	
	elem(){
		for(int i = 0; i < 2; i++){
			b[i] = 0;
			for(int j = 0; j < 2; j++){
				a[i][j] = 0;
			}
		}
	}
	
};

elem operator + (const elem &a, const elem &b){
	elem c;
	for(int i = 0; i < 2; i++){
		c.b[i] = min(a.b[i] + b.b[i], inf);
		for(int j = 0; j < 2; j++){
			c.a[i][j] = min(a.a[i][j] + b.a[i][j] + (a.last == i && b.first == j), inf);
		}
	}
	c.first = a.first;
	c.last = b.last;
	return c;
}

elem d[K];
bool can[N][N][3][3];

inline void init(){
	for(int i = 0; i < 3; i++){
		can[1][0][i][i] = true;
	}
	for(int i = 1; i + 1 < N; i++){
		for(int j = 0; j < i; j++){
			for(int z = 0; z < 3; z++){
				for(int h = 0; h < 3; h++){
					if(!can[i][j][z][h]){
						continue;
					}
					for(int x = 0; x < 3; x++){
						int nj = j;
						if(h == 0 && x == 1){
							nj++;
						}
						can[i + 1][nj][z][x] = true;
					}
				}
			}
		}
	}
}

void path(int n, int m, int f, int l){
	if(n == 1){
		printf("%c", ch[f]);
		return;
	}
	for(int i = 0; i < 3; i++){
		int nm = m;
		if(i == 0 && l == 1){
			nm--;
		}
		if(nm >= 0 && can[n - 1][nm][f][i]){
			path(n - 1, nm, f, i);
			break;
		}
	}
	printf("%c", ch[l]);
}

int main(){
	int k, x, n, m;
	scanf("%d %d %d %d", &k, &x, &n, &m);
	init();
	for(int f1 = 0; f1 < 3; f1++){
		for(int l1 = 0; l1 < 3; l1++){
			if(n == 1 && f1 != l1){
				continue;
			}
			for(int f2 = 0; f2 < 3; f2++){
				for(int l2 = 0; l2 < 3; l2++){
					if(m == 1 && f2 != l2){
						continue;
					}
					d[1] = elem();
					d[1].first = d[1].last = 0;
					d[1].b[0] = 1;
					d[2] = elem();
					d[2].first = d[2].last = 1;
					d[2].b[1] = 1;
					for(int i = 3; i <= k; i++){
						d[i] = d[i - 2] + d[i - 1];
					}
					for(int i = 0; i < n; i++){
						if(!can[n][i][f1][l1]){
							continue;
						}
						for(int j = 0; j < m; j++){
							if(!can[m][j][f2][l2]){
								continue;
							}
							ll cur = i * d[k].b[0] + j * d[k].b[1];
							if(l1 == 0 && f1 == 1){
								cur += d[k].a[0][0];
							}
							if(l1 == 0 && f2 == 1){
								cur += d[k].a[0][1];
							}
							if(l2 == 0 && f1 == 1){
								cur += d[k].a[1][0];
							}
							if(l2 == 0 && f2 == 1){
								cur += d[k].a[1][1];
							}
							if(cur == x){
								path(n, i, f1, l1);
								puts("");
								path(m, j, f2, l2);
								puts("");
								return 0;
							}
						}
					}
				}
			}
		}
	}
	puts("Happy new year!");
	return 0;
}