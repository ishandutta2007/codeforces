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

char s[200];
const int md = 1000000007;
int dp[105][105 * 27];
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	int T;
	scanf("%d", &T);
	dp[0][0] = 1;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100 * 26; j++) {
			for (int k = 0; k < 26; k++) {
				dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j]) % md;
			}
		}
	}
	while (T --> 0) {
		scanf("%s", s);
		int n = strlen(s);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += s[i] - 'a';
		}
		cout<<(dp[n][sum] + md - 1) % md<<endl;
	} 
	return 0;
}