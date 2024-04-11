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
const int N = 20;

int n;
char a[N + 10][N + 10];
int used[30][N + 10][N + 10];
int num[N + 10][N + 10];
int x[2 * N + 10], y[2 * N + 10], sz[2 * N + 10];
int d[(1 << N) + 10], nd[(1 << N) + 10];
vector <pii> lst[30];

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main(){
	scanf("%d", &n);
	gets(a[0]);
	for(int i = 0; i < n; i++){
		gets(a[i]);
		for(int j = 0; j < n; j++){
			a[i][j] -= 'a';
		}
	}
	int cx = 0, cy = 0;
	for(int i = 0; i < 2 * n - 1; i++){
		x[i] = cx;
		y[i] = cy;
		sz[i] = 0;
		int ix = cx, iy = cy;
		while(good(ix, iy)){
			num[ix][iy] = sz[i]++;
			ix++;
			iy--;
		}
		cy++;
		if(cy >= n){
			cy = n - 1;
			cx++;
		}
	}
	int step = 0;
	for(int i = 2 * n - 3; i >= 0; i--){
		for(int j = 1; j < (1 << sz[i]); j++){
			for(int z = 0; z < 26; z++){
				lst[z].clear();
			}
			int cx = x[i], cy = y[i];
			step++;
			for(int z = 0; z < sz[i]; z++){
				if((j & (1 << z)) != 0){
					if(good(cx, cy + 1) && used[a[cx][cy + 1]][cx][cy] != step){
						used[a[cx][cy + 1]][cx][cy] = step;
						lst[a[cx][cy + 1]].pb(mp(cx, cy));
					}
					if(good(cx + 1, cy) && used[a[cx + 1][cy]][cx][cy] != step){
						used[a[cx + 1][cy]][cx][cy] = step;
						lst[a[cx + 1][cy]].pb(mp(cx, cy));
					}
				}
				cx++;
				cy--;
			}
			if(i % 2 != 0){
				nd[j] = -inf;
			}
			else{
				nd[j] = inf;
			}
			for(int z = 0; z < 26; z++){
				int nj = 0;
				for(int h = 0; h < sz(lst[z]); h++){
					cx = lst[z][h].fs;
					cy = lst[z][h].sc;
					if(good(cx, cy + 1) && a[cx][cy + 1] == z){
						nj |= (1 << num[cx][cy + 1]);
					}
					if(good(cx + 1, cy) && a[cx + 1][cy] == z){
						nj |= (1 << num[cx + 1][cy]);
					}
				}
				if(nj == 0){
					continue;
				}
				int res = d[nj];
				if(z == 0){
					res++;
				}
				if(z == 1){
					res--;
				}
				if(i % 2 != 0){
					nd[j] = max(nd[j], res);
				}
				else{
					nd[j] = min(nd[j], res);
				}
			}
		}
		for(int j = 1; j < (1 << sz[i]); j++){
			d[j] = nd[j];
		}
	}
	int res = d[1];
	if(a[0][0] == 0){
		res++;
	}
	if(a[0][0] == 1){
		res--;
	}
	if(res == 0){
		puts("DRAW");
		return 0;
	}
	if(res > 0){
		puts("FIRST");
		return 0;
	}
	puts("SECOND");
	return 0;
}