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
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int n, m, k;
map<int, vector<pi> > MX;
map<int, int> S;
void prnt(int x, int y1, int y2) {
	assert(y1 != y2);
	int x1 = x;
	int x2 = x;
	if (x1 > n) {
		x1 -= n + 1;
		x2 -= n + 1;
		swap(x1, y1);
		swap(x2, y2);
	}
	printf("%d %d %d %d\n", x1, y1, x2, y2);
	exit(0);
}
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	scanf("%d %d %d", &n, &m, &k);
	int kn = n - 1;
	int km = m - 1;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == x2) {
			if (MX[x1].empty()) {
				MX[x1].pb(mp(0, 1));
				MX[x1].pb(mp(0, -1));
				MX[x1].pb(mp(m, 1));
				MX[x1].pb(mp(m, -1));
				kn--;
			}
			MX[x1].pb(mp(min(y1, y2), -1));
			MX[x1].pb(mp(max(y1, y2), 1));
		} else {
			swap(x1, y1);
			swap(x2, y2);
			x1 += n + 1;
			x2 += n + 1;
			if (MX[x1].empty()) {
				MX[x1].pb(mp(0, 1));
				MX[x1].pb(mp(0, -1));
				MX[x1].pb(mp(n, 1));
				MX[x1].pb(mp(n, -1));
				km--;
			}
			MX[x1].pb(mp(min(y1, y2), -1));
			MX[x1].pb(mp(max(y1, y2), 1));
		}
	}
	for (int i = 1; i < n; i++) {
		if (MX[i].empty()) {
			int x1 = i;
			MX[x1].pb(mp(0, 1));
			MX[x1].pb(mp(0, -1));
			MX[x1].pb(mp(m, 1));
			MX[x1].pb(mp(m, -1));
			kn--;
			break;
		}
	}
	for (int i = 1; i < m; i++) {
		if (MX[i + n + 1].empty()) {
			int x1 = i + n + 1;
			MX[x1].pb(mp(0, 1));
			MX[x1].pb(mp(0, -1));
			MX[x1].pb(mp(n, 1));
			MX[x1].pb(mp(n, -1));
			km--;
			break;
		}
	}
	int xr = ((kn % 2) * m) ^ ((km % 2) * n);
	for (map<int, vector<pi> >::iterator it = MX.begin(); it != MX.end(); ++it) {
		vector<pi> ls = it->y;
		sort(all(ls));
		int sum = 0;
		int tk = 0;
		for (int i = 0; i < sz(ls) - 1; i++) {
			tk += ls[i].y;
			if (tk == 0) {
				sum += ls[i + 1].x - ls[i].x;
			}
		}
		S[it->x] = sum;
		xr ^= sum;
	}
	if (xr == 0) {
		printf("SECOND\n");
		return 0;
	}
	printf("FIRST\n");
	for (map<int, vector<pi> >::iterator it = MX.begin(); it != MX.end(); ++it) {
		vector<pi> ls = it->y;
		sort(all(ls));
		int sum = 0;
		int tk = 0;
		int F = xr ^ S[it->x];
		if (F == 0) {
			prnt(it->x, 0, ls[sz(ls) - 1].x);			
		}
		if (S[it->x] > F) {
			int del = S[it->x] - F;
			for (int i = 0; i < sz(ls) - 1; i++) {
				tk += ls[i].y;
				if (tk == 0) {					
					if (sum + ls[i + 1].x - ls[i].x >= del) {
						prnt(it->x, 0, ls[i].x + del - sum);			
					}
					sum += ls[i + 1].x - ls[i].x;
				}
			}		
		}
	}
	assert(false);	
	return 0;
}