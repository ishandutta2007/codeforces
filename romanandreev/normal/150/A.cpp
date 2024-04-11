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

const int MAXP = 3200000;
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	ll n, n0;
	vector<ll> v;
	cin>>n;
	n0 = n;
	for (int i = 2; n > 1 && i < MAXP ; i++) {
		while (n % i == 0) {
			v.pb(i);
			n /= i;
		}
	}
	if (n != 1) {
		v.pb(n);
	}
	if (sz(v) <= 1) {
		printf("1\n");	
		printf("0\n");
		return 0;
	}
	if (sz(v) == 2) {
		printf("2\n");
		return 0;
	}
	printf("1\n");
	cout<<v[0] * v[1]<<endl;
	return 0;
}