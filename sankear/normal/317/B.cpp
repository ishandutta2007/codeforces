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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
const int D = 70;

int d[2 * D + 100][2 * D + 100];
int nd[2 * D + 100][2 * D + 100];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	d[D][D] = n;
	int iters = 0;
	while(true){
		bool fl = false;
		for(int i = 0; i <= 2 * D; i++){
			for(int j = 0; j <= 2 * D; j++){
				nd[i][j] = 0;
			}
		}
		for(int i = 0; i <= 2 * D; i++){
			for(int j = 0; j <= 2 * D; j++){
				int k = d[i][j] / 4;
				if(k > 0){
					fl = true;
					for(int z = 0; z < 4; z++){
						nd[i + dx[z]][j + dy[z]] += k;
					}
				}
				int ost = d[i][j] - 4 * k;
				nd[i][j] += ost;
			}
		}
		for(int i = 0; i <= 2 * D; i++){
			for(int j = 0; j <= 2 * D; j++){
				d[i][j] = nd[i][j];
			}
		}
		if(!fl){
			break;
		}
		iters++;
	}
	cerr << iters << endl;
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x += D;
		y += D;
		if(x < 0 || x > 2 * D || y < 0 || y > 2 * D){
			puts("0");
			continue;
		}
		printf("%d\n", d[x][y]);
	}
	return 0;
}