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

int n, ans;
int a[100000];
int gg[100000];

int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += a[i];
	}
	for (int i = 1; i <= n; i++) if (n % i == 0 && n / i >= 3){
		for (int j = 0; j < n; j++) {
			gg[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			gg[j % i] += a[j];
		}
		for (int j = 0; j < i; j++) {
			ans = max(ans, gg[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}