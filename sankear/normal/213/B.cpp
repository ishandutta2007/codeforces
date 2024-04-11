#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);
const ll MOD = ll(1e9 + 7);

int a[20];
ll c[200][200], d[20][200][200];

inline void norm(ll &a){
	while(a >= MOD){
		a -= MOD;
	}
}

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("coingame.in", "r", stdin);
	//freopen("coingame.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i <= n; i++){
		c[i][0] = 1;
		for(int j = 1; j <= i; j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			norm(c[i][j]);
		}
	}
	ll ans = 0;
	for(int i = 1; i < 10; i++){
		a[i]--;
		for(int j = 0; j <= 10; j++){
			for(int z = 0; z < n; z++){
				for(int h = 0; h <= z; h++){
					d[j][z][h] = 0;
				}
			}
		}
		for(int j = 0; j < n; j++){
			d[0][j][0] = 1;
		}
		for(int j = 0; j < 10; j++){
			for(int z = 0; z < n; z++){
				for(int h = 0; h <= z; h++){
					for(int x = max(a[j], 0); h + x <= z; x++){
						d[j + 1][z][h + x] = (d[j + 1][z][h + x] + d[j][z][h] * c[z - h][x]) % MOD;
					}
				}
			}
		}
		for(int j = 0; j < n; j++){
			ans += d[10][j][j];
			norm(ans);
		}
		a[i]++;
	}
	printf("%I64d\n", ans);
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}