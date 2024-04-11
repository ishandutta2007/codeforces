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

const int P1 = 1000081;
const int maxn = 1001000;
ll stp1[maxn];
int n, m;
vi a[maxn];
vector<vector<ll> > H1;
vector<ll> M; 
ll calc(int i, int j) {
	return H1[i - 1][0] + (H1[i - 1][j + 1] - H1[i - 1][j]) * stp1[j];
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	stp1[0] = 1;
	for (int i = 1; i < maxn; i++) {
		stp1[i] = stp1[i - 1] * P1;
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].pb(y);
		a[y].pb(x);
	}
	H1.reserve(n);
	for (int i = 1; i <= n; i++) {
		sort(all(a[i]));
		a[i].resize(unique(all(a[i])) - a[i].begin());
		vector<ll> h1(sz(a[i]) + 1, 0);
		for (int j = sz(a[i]) - 1; j >= 0; j--) {
			h1[j] = h1[j + 1] * P1 + a[i][j];
		}
		M.pb(h1[0]);
		H1.pb(h1);
	}
	sort(all(M));
	ll ans = 0;
	int pr = -1;
	for (int i = 0; i < sz(M); i++) {
		if (i == sz(M) - 1 || M[i] != M[i + 1]) {
			int k = i - pr;
			ans += ((ll)k * (k - 1)) / 2;
			pr = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz(a[i]); j++) {
			if (i < a[i][j]) {
				if (calc(i, j) == calc(a[i][j], lower_bound(all(a[a[i][j]]), i) - a[a[i][j]].begin())) {
					ans++;
				}
			}	
		}
	}
	cout<<ans<<endl;
	return 0;            
}