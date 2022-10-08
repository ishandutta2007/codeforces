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

char s[1000000];
int a1[100];
int a2[100];
int ff1[100];
int ff2[100];

int gg, gg0;
vi ans1, ans2;
int calc() {
	int res = 0;
	for (int i = 0; i <= 9; i++) {
		ff1[i] = a1[i];
		ff2[i] = a2[i];
	}
	for (int i = 0; i <= 9; i++) {
		res += min(a1[i], a2[9 - i]);
		int zz = min(a1[i], a2[9 - i]);
		ff1[i] -= zz;
		ff2[9 - i] -= zz;
	}
	gg = min(ff1[0], ff2[0]);
	return res + 1 + min(ff1[0], ff2[0]);
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		a1[s[i] - '0']++;
		a2[s[i] - '0']++;
	}
	int mx = 0;
	int mxi = 0;
	int ff;
	for (int i = 1; i <= 9; i++) {
		if (a1[i] > 0 && a2[10 - i] > 0) {
			a1[i]--;
			a2[10 - i]--;
			if ((ff = calc()) > mx) {
				mx = ff;
				mxi = i;
				gg0 = gg;
			}
			a1[i]++;
			a2[10 - i]++;
		}
	}
	if (mxi == 0) {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < a1[i]; j++) {
				printf("%d", i);
			}
		}
		printf("\n");
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < a1[i]; j++) {
				printf("%d", i);
			}
		}
		printf("\n");
		return 0;
	}

	a1[mxi]--;
	a2[10 - mxi]--;
	for (int j = 0; j < gg0; j++) {
		ans1.pb(0);
		ans2.pb(0);
		a1[0]--;
		a2[0]--;
	}
	assert(a1[0] >= 0);
	assert(a2[0] >= 0);
	ans1.pb(mxi);
	ans2.pb(10 - mxi);
	for (int i = 0; i <= 9; i++) {
		while(min(a1[i], a2[9 - i]) > 0) {
			ans1.pb(i);
			ans2.pb(9 - i);
			a1[i]--;
			a2[9 - i]--;
		}
	}
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j < a1[i]; j++) {
			ans1.pb(i);
		}
		for (int j = 0; j < a2[i]; j++) {
			ans2.pb(i);
		}
	}
	assert(sz(ans1) == n);
	assert(sz(ans2) == n);
	for (int i = 0; i < n; i++) {
		printf("%d", ans1[n - 1 - i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d", ans2[n - 1 - i]);
	}
	printf("\n");
	return 0;
}