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

int a1, a2, a3, a4, d, ans;
int was[1000000];
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif
	cin>>a1>>a2>>a3>>a4>>d;
	for (int i = 0; i <= d; i+=a1) {
		was[i] = 1;
	}
	for (int i = 0; i <= d; i+=a2) {
		was[i] = 1;
	}
	for (int i = 0; i <= d; i+=a3) {
		was[i] = 1;
	}
	for (int i = 0; i <= d; i+=a4) {
		was[i] = 1;
	}
	ans = 0;
	for (int i = 1; i <= d; i++) {
		ans += was[i];
	}
	cout<<ans<<endl;
	return 0;
}