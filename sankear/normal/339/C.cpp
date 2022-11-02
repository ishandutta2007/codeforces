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
const int MAGIC = 20;
const int W = 10;
const int N = 1000;

char s[20];
bool good[20];
int lst[N + 10];
bool can[N + 2][W + 2][2 * MAGIC + 2];
int prev[N + 2][W + 2][2 * MAGIC + 2];

void path(int pos, int w, int d){
	if(pos > 0){
		if((pos - 1) % 2 == 0){
			path(pos - 1, prev[pos][w][d + MAGIC], d - w);
		}
		else{
			path(pos - 1, prev[pos][w][d + MAGIC], d + w);
		}
		lst[pos] = w;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(prev) + sizeof(can)) / 1024 / 1024 << endl;
	gets(s);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 10; i++){
		good[i] = (s[i] == '1');
	}
	can[0][0][0 + MAGIC] = true;
	for(int i = 0; i < n; i++){
		for(int j = (i > 0); j <= 10; j++){
			for(int z = -MAGIC; z <= MAGIC; z++){
				if(!can[i][j][z + MAGIC]){
					continue;
				}
				for(int h = 1; h <= 10; h++){
					if(!good[h - 1] || h == j){
						continue;
					}
					if(i % 2 == 0 && z + h > 0){
						can[i + 1][h][z + h + MAGIC] = true;
						prev[i + 1][h][z + h + MAGIC] = j;
					}
					if(i % 2 != 0 && z - h < 0){
						can[i + 1][h][z - h + MAGIC] = true;
						prev[i + 1][h][z - h + MAGIC] = j;
					}
				}
			}
		}
	}
	for(int i = 1; i <= 10; i++){
		for(int j = -MAGIC; j <= MAGIC; j++){
			if(can[n][i][j + MAGIC]){
				path(n, i, j);
				puts("YES");
				for(int i = 1; i <= n; i++){
					printf("%d ", lst[i]);
				}
				puts("");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}