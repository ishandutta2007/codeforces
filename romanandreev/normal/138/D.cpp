#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif
int M[2][20][20][20][20];
char b[2][100][100];
char a[100][100];
int cnt = 0;
int gg[1000000];
int calc(int cc, int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) return 0;
	if (M[cc][x1][y1][x2][y2] != -1) {
		return M[cc][x1][y1][x2][y2];
	}
	vector<int> ff;
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++) {
			if (b[cc][i][j] == 'L') {
				ff.pb(calc(cc, x1, y1, i - 1, y2) ^ calc(cc, i + 1, y1, x2, y2));
			}
			if (b[cc][i][j] == 'R') {
				ff.pb(calc(cc, x1, y1, x2, j - 1) ^ calc(cc, x1, j + 1, x2, y2));
			}
			if (b[cc][i][j] == 'X') {
				ff.pb(calc(cc, x1, y1, i - 1, j - 1) ^ calc(cc, i + 1, j + 1, x2, y2) ^ 
					  calc(cc, x1, j + 1, i - 1, y2) ^ calc(cc, i + 1, y1, x2, j - 1));
			}
	}
	cnt++;
	for (int i = 0; i < sz(ff); i++) {
		gg[ff[i]] = cnt;
	}
	for (int i = 0;;i++) {
		if (gg[i] != cnt) {
			return M[cc][x1][y1][x2][y2] = i;
		}
	}
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	int n0, m0, n, m;
	scanf("%d %d", &n0, &m0);
	for (int i = 0; i < n0; i++) {
		scanf("%s", a[i]);
		for (int j = 0; j < m0; j++) {
			if (((i + j) & 1) == 0) {
				b[0][(i + j) / 2][(i - j + m0 - 1) / 2] = a[i][j];
			} else {
				b[1][(i + j) / 2][(i - j + m0 - 1) / 2] = a[i][j];
			}
		}
	}
	memset(M, -1, sizeof(M));
	n = n0 + m0;
	m = n0 + m0;
	int res = calc(0, 0, 0, n / 2 - 1, m / 2 - 1) ^ calc(1, 0, 0, n / 2 - 1, m / 2 - 1);
	if (res == 0) printf("LOSE\n"); else
				  printf("WIN\n");
	return 0;
}