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
int n, k, h;
pair<pi,int> p[1000000];

int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d %d", &n, &k, &h);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i].x.x);
		p[i].y = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i].x.y);
	}
	sort(p, p + n);
	ld l, r, m;
	l = 0;
	r = 1e9 + 1;
	for (int it = 0; it <= 100; it++) {
		m = (l + r) / 2;
		int tk = 1;
		for (int i = 0; i < n; i++) {
			ll nm = (ll)(m * p[i].x.y / h);
			if (nm >= tk) {
				tk++;
			}
		}
		if (tk > k) {
			r = m;
		} else {
			l = m;
		}
	}
	m = r;
		int tk = 1;
		for (int i = 0; i < n; i++) {
			ll nm = (ll)(m * p[i].x.y / h);
			if (nm >= tk && tk <= k) {
				printf("%d ", p[i].y + 1);
				tk++;
			}
		}
		printf("\n");
	return 0;
}