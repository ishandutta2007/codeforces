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
const int N = 44;

bool good[N];
char a[N][N];
ll f[N][N][N][N];

inline void gen(){
	freopen("input.txt", "w", stdout);
	int n = 40, m = 40, q = int(3e5);
	cout << n << " " << m << " " << q << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << char('0' + rand() % 2);
		}
		cout << endl;
	}
	for(int i = 0; i < q; i++){
		cout << "1 1 " << n << " " << m << endl;
	}
	exit(0);
}

int main(){
	//gen();
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	gets(a[0]);
	for(int i = 0; i < n; i++){
		gets(a[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			good[j] = true;
		}
		for(int j = i; j < n; j++){
			for(int z = 0; z < m; z++){
				if(a[j][z] == '1'){
					good[z] = false;
				}
			}
			for(int z = 0; z < m; z++){
				int last = z - 1;
				ll res = 0;
				for(int h = z; h < m; h++){
					if(!good[h]){
						f[z][h][i][j] = res;
						last = h;
						continue;
					}
					res -= ll(h - last) * (h - last - 1) / 2;
					res += ll(h - last + 1) * (h - last) / 2;
					f[z][h][i][j] = res;
				}
			}
		}
	}
	for(int i = 0; i < q; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		x2--;
		y2--;
		ll ans = 0;
		for(int j = x1; j <= x2; j++){
			for(int z = j; z <= x2; z++){
				ans += f[y1][y2][j][z];
			}
		}
		printf(LLD"\n", ans);
	}
	return 0;
}