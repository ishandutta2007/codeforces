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
int a[1000000];
map<int, int> M;
set<pair<int, int> > S;
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		M[a[i]]++;
	}
	sort(a, a + n);
	m = unique(a, a + n) - a;
	for (int i = 0; i < m; i++) {
		S.insert(mp(M[a[i]], a[i]));
	}
	vector<vector<int> > ans;
	while (sz(S) >= 3) {	
		vector<pi> v;
		vector<int> aa;
		for (int i = 0; i < 3; i++) {
			v.pb(*S.rbegin());
			v[i].fs--;
			swap(v[i].fs, v[i].sc);
			S.erase(*S.rbegin());
		}
		sort(all(v));
		reverse(all(v));
		for (int i = 0; i < 3; i++) {
			swap(v[i].fs, v[i].sc);
			if (v[i].fs > 0) {
				S.insert(v[i]);
			}
			aa.pb(v[i].sc);
		}
		ans.pb(aa);
	}
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}