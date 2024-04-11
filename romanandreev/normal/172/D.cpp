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
const int maxn = 10000010;
int d[maxn + 10];
vi p;
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	for (int i = 2; i <= maxn; i++) {
		if (d[i] == 0) {
			d[i] = i;
			p.pb(i);
		}
		for (int j = 0; j < sz(p) && p[j] <= d[i] && p[j] * i <= maxn; j++) {
			d[p[j] * i] = p[j];
		}
	}
	int a, n;
	cin>>a>>n;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int tk = a + i;
		int last = 1;
		int cc = 0;
		int ff = 1;
		while (tk > 1) {	
			if (d[tk] == last) {
				cc++;
			} else {
				if (cc % 2 == 1) {
					ff *= last;
				}
				last = d[tk];
				cc = 1;
			}
			tk = tk / d[tk];
		}
		if (cc % 2 == 1) {
			ff *= last;
		}
		//cerr<<a + i<<" "<<ff<<endl;
		ans += ff;
	}
	cout<<ans<<endl;
	return 0;
}