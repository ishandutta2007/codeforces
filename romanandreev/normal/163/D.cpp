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
int k;
ll p[1000];
int a[1000];
int b[1000];
ll stp[100][100];
ll f1, f2, f3, mn, a1, a2, a3, n;
void bct1(int f) {
	if (f == 0) {		
		f3 = n / (f1 * f2);
	    if (f1 * f2 + f2 * f3 + f1 * f3 <= mn) {
			mn = f1 * f2 + f2 * f3 + f1 * f3;
			a1 = f1;
			a2 = f2;
			a3 = f3;	
		}
		return;
	}
	ll ff0 = f2;
	for (int i = b[f - 1]; i >= 0; i--) {
		f2 = ff0 * stp[f - 1][i];
		if ((ld)f2 * f2 * f1 < n + 1) {
			bct1(f - 1);
		}
	}
	f2 = ff0;
}
void bct(int f) {
	if (f == 0) {
		if (f1 * (2 * sqrt(n / f1)) + n / f1 > mn + 1) return;		
	    bct1(k);
		return;
	}
	ll ff0 = f1;
	for (int i = a[f - 1]; i >= 0; i--) {
		b[f - 1] = a[f - 1] - i;
		f1 = ff0 * stp[f - 1][i];
		if ((ld)f1*f1*f1 < n + 1) {
			bct(f - 1);
		}
	}
	f1 = ff0;
}

int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	int T;
	scanf("%d", &T);
	while(T-->0) {
		cin>>k;
		n = 1;
		for (int i = 0; i < k; i++) {
			cin>>p[i]>>a[i];
			stp[i][0] = 1;
			for (int j = 1; j <= a[i]; j++) {
				stp[i][j] = stp[i][j - 1] * p[i];
			}
			n = n * stp[i][a[i]];
		}
		f1 = 1;
		f2 = 1;
		f3 = 1;
		mn = (ll)3*1e18;
		bct(k);
		cout<<mn * 2<<" "<<a1<<" "<<a2<<" "<<a3<<endl;
	}
//	cerr<<clock()*1./CLOCKS_PER_SEC<<endl;
	return 0;
}