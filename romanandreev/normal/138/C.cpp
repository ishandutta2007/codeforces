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

int n, m;
int ff[1000];
int a[1000000];
int h[1000000];
int l[1000000];
int r[1000000];
vector<pair<pi, int> > sb;
ld poww(ld x, int stp) {
	if (stp == 0) return 1;
	ld res = poww(x, stp>>1);
	res = res * res;
	if ((stp & 1) == 1) {
	    res = res * x;
	}
	return res;
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i], &h[i], &l[i], &r[i]);
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		sb.pb(mp(mp(x, 0), y));
	}
	for (int i = 0; i < n; i++) {
		sb.pb(mp(mp(a[i] - h[i], -1), 100 - l[i]));
		sb.pb(mp(mp(a[i] - 1, 1), 100 - l[i]));
		sb.pb(mp(mp(a[i] + 1, -1), 100 - r[i]));
		sb.pb(mp(mp(a[i] + h[i], 1), 100 - r[i]));
	}
	sort(all(sb));
	ld ans = 0;
	for (int i = 0; i < sz(sb); i++) {
		if (sb[i].fs.sc == -1) {
			ff[sb[i].sc]++;
		} else
		if (sb[i].fs.sc == 1) {
			ff[sb[i].sc]--;
		} else {
			ld tk = sb[i].sc;
			for (int j = 0; j <= 100; j++) {
				tk = tk * poww(j/100.0, ff[j]);
			}
			ans += tk;
		}
	}
	printf("%.18lf\n", (double)ans);
	return 0;
}