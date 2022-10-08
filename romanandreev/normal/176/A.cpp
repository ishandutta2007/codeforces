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
int n, m, K;
ll ans;
int a[100][200];
int b[100][200];
int c[100][200];
string s;

int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	cin>>n>>m>>K;
	for (int i = 0; i < n; i++) {
		cin>>s;
		for (int j = 0; j < m; j++) {
			cin>>a[i][j]>>b[i][j]>>c[i][j];
		}
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll s = 0;
			vector<int> v;
			for (int k = 0; k < m; k++) {
				for (int t = 0; t < c[i][k]; t++)
				v.pb(max(0, (b[j][k] - a[i][k])));
			}
			sort(all(v));
			reverse(all(v));
			for (int i = 0; i < min(sz(v), K); i++) {
				s += v[i];
			}
			ans = max(ans, s);
		}
	}
	cout<<ans<<endl;
	return 0;
}