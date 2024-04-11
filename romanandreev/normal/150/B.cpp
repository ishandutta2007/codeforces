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

const ll p = (ll)1e9 + 7;
int n , m, k;
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	cin>>n>>m>>k;
	if (k > n) {
		k = 1;
	}
	if (k % 2 == 0) {
		if (k == n) {
			ll ans = 1;
			for (int i = 0; i < n / 2; i++) {
				ans = (ans * m) % p;
			}
			cout<<ans<<endl;  	
			return 0;
		} else {
			cout<<m<<endl;
			return 0;
		}
	} else {
		if (k == 1) {
			ll ans = 1;
			for (int i = 0; i < n; i++) {
				ans = (ans * m) % p;
			}
			cout<<ans<<endl;
			return 0;
		} else
		if (k == n) {
			ll ans = 1;
			for (int i = 0; i < (n + 1) / 2; i++) {
				ans = (ans * m) % p;
			}
			cout<<ans<<endl;
			return 0;
		} else {					
			cout<<m * m<<endl;
			return 0;
		}
	}
	return 0;
}