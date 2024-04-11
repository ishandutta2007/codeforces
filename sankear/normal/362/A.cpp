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

const int dx[] = {-2, -2, 2, 2};
const int dy[] = {-2, 2, -2, 2};

char a[20][20];
bool can[20][20][20][20];

inline bool good(int x, int y){
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void dfs(int x1, int y1, int x2, int y2){
	can[x1][y1][x2][y2] = true;
	for(int i = 0; i < 4; i++){
		int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
		if(!good(nx1, ny1)){
			continue;
		}
		for(int j = 0; j < 4; j++){
			int nx2 = x2 + dx[j], ny2 = y2 + dy[j];
			if(!good(nx2, ny2)){
				continue;
			}
			if(!can[nx1][ny1][nx2][ny2]){
				dfs(nx1, ny1, nx2, ny2);
			}
		}
	}
}

inline void solve(){
	gets(a[0]);
	for(int i = 0; i < 8; i++){
		gets(a[i]);
	}
	int x1 = -1, y1, x2, y2;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(a[i][j] == 'K'){
				if(x1 == -1){
					x1 = i;
					y1 = j;
				}
				else{
					x2 = i;
					y2 = j;
				}
			}
		}	
	}
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			for(int z = 0; z < 8; z++){
				for(int h = 0; h < 8; h++){
					can[i][j][z][h] = false;
				}
			}
		}
	}
	dfs(x1, y1, x2, y2);
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(a[i][j] != '#' && can[i][j][i][j]){
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		solve();
	}
	return 0;
}