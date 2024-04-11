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

string ss[100000];
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	string gr = "aeiou";
	string s;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 4 * n; i++) {
		cin >> s;
		int cnt = 0;
		ss[i] = "";
		int start = -1;
		for (int j = sz(s) - 1; j >= 0; j--) {
			bool bl = false;
			for (int jj = 0; jj < sz(gr); jj++) {
				if (s[j] == gr[jj]) {
					bl = true;
					break;
				}
			}
			if (bl) {
				cnt++;
				if (cnt == k) {
					start = j;
				}
			}
		}
		for (int j = start; j < sz(s); j++) {
			ss[i] += s[j];
		}
		if (start == -1) {
			printf("NO\n");
			return 0;
		}
	}
	bool can1 = true;
	bool can2 = true;
	bool can3 = true;
	for (int i = 0; i < n; i++) {
		if (ss[4 * i] != ss[4 * i + 1] || ss[4 * i + 2] != ss[4 * i + 3])
			can1 = false;
		if (ss[4 * i] != ss[4 * i + 2] || ss[4 * i + 1] != ss[4 * i + 3])
			can2 = false;
 	    if (ss[4 * i] != ss[4 * i + 3] || ss[4 * i + 1] != ss[4 * i + 2])
			can3 = false;
	}
	if (can1 && can2) printf("aaaa\n"); else
	if (can1) printf("aabb\n"); else
	if (can2) printf("abab\n"); else
	if (can3) printf("abba\n"); else
	printf("NO\n");
	return 0;
}