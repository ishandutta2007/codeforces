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
const int maxn = 100100;
int d[2 * maxn];
int was[2 * maxn];
set<int> M[2 * maxn];
vi pr;
vi obr(int x) {
	vi a;
	while (x > 1) {
		a.pb(d[x]);
		x /= d[x];
	}
	sort(all(a));
	a.resize(unique(all(a))-a.begin());
	return a;
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	for (int i = 2; i <= maxn; i++) {
		if (d[i] == 0) {
			d[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < sz(pr) && pr[j] <= d[i] && pr[j] * i <= maxn; j++) {
			d[pr[j] * i] = pr[j];
		}
	}
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < m; i++) {
		char t;
		int x;
		scanf("%c %d\n", &t, &x);
		if (t == '+') {
			if (was[x] == 1) {
				printf("Already on\n");
				continue;
			}
			vi pp = obr(x);
			bool bl = true;
			for (int i = 0; i < sz(pp); i++) {
            	if (sz(M[pp[i]]) != 0) {
            		printf("Conflict with %d\n", *M[pp[i]].begin());
            		bl = false;
            		break;
            	}
            }
			if (!bl) continue;
			for (int i = 0; i < sz(pp); i++) {
            	M[pp[i]].insert(x);
            }
            printf("Success\n");
            was[x] = 1;
		} else {
			if (was[x] == 0) {
				printf("Already off\n");
				continue;
			}
			vi pp = obr(x);
            for (int i = 0; i < sz(pp); i++) {
            	M[pp[i]].erase(x);
            }
            was[x] = 0;
            printf("Success\n");
		}
	}
	return 0;
}