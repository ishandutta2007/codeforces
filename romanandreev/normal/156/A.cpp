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


int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	int ans;
	string s1,s2,ss = "";
	cin>>s1>>s2;

	for (int i = 0; i < sz(s2); i++) {
		ss += '-';
	} 
	s1 = ss + s1 + ss;
	ans = sz(s2);
	for (int i = 0; i < sz(s1) - sz(s2) + 1; i++) {
		int cnt = 0;
		for (int j = 0; j < sz(s2); j++) {
			if (s1[i + j] != s2[j]) {
				cnt++;
			}
		}
		ans = min(ans, cnt);
	}

	cout<<ans<<endl;
	return 0;
}