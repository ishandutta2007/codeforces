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

int n, m, sumn;
int x[1000000];
int kill[1000000];
int nkill[1000000];
int killer[1000000];

vi vv;
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d", &n, &m);
	sumn = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		if (x[i] > 0) {
			kill[x[i] - 1]++;
		} else {
			sumn++;
			nkill[-x[i] - 1]++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (kill[i] + sumn - nkill[i] == m) {
			killer[i] = 1;
			vv.pb(i);
		}
	}
	if (sz(vv) == 1) {
		for (int i = 0; i < n; i++) {
			if ((x[i] > 0 && killer[x[i] - 1] == 1) || (x[i] < 0 && killer[-x[i] - 1] == 0)) {
				printf("Truth\n");
			} else {
				printf("Lie\n");
			}
		}
		return 0;
	} 
	for (int i = 0; i < n; i++) {
		if (x[i] > 0) {
			if (killer[x[i] - 1] == 1){
				printf("Not defined\n");
			} else {
				printf("Lie\n");
			}
		} else {
			if (killer[-x[i] - 1] == 0) {
				printf("Truth\n");
			} else {
				printf("Not defined\n");
			}
		}
	}
	return 0;
}