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
ll vp(pi a, pi b) {
	return (ll)a.x * b.y - (ll)a.y * b.x;
}
pi mn(pi a, pi b) {
	return mp(a.x - b.x, a.y - b.y);
}
int main(){
	srand(239);
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	int n, m;
	scanf("%d %d", &n, &m);
	if (m == 3) {
		if (n > 4) {
			printf("-1\n");
			return 0;
		}
		if (n == 3) {
			printf("0 0\n0 1\n1 0\n");
			return 0;
		}
		if (n == 4) {
			printf("0 0\n0 3\n3 0\n1 1\n");
			return 0;
		}
		assert(false);
	}
	int R1 = 1e7;
	int R2 = 2e7;
	vector<pi> v;
	for (int i = 0; i < m; i++) {
		v.pb(mp(R1 * cos(M_PI * 2 * i / m), R1 * sin(M_PI * 2 * i / m)));
		if (i < n - m)
		v.pb(mp(R2 * cos(M_PI * 2 * i / m + M_PI * 2 / m / m), R2 * sin(M_PI * 2 * i / m + M_PI * 2 / m / m)));
	}
/*	while (1) {
		bool good = true;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (vp(mn(v[i], v[k]), mn(v[j], v[k])) == 0) {
						v[k].x += rand() % 10;
						v[k].y += rand() % 10;
						good = false;
					}
				}
			}
		}
		if (good) break;
	}*/
	assert(sz(v) == n);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", v[i].x, v[i].y);
	}
	return 0;
}