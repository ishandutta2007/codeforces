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

char s[200000];
int n;
int a[27][27];
int dp[200000][27];

int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%s\n", s);
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		char c1, c2;
		scanf("%c%c\n", &c1, &c2);
		a[c1 - 'a'][c2 - 'a'] = 1;
		a[c2 - 'a'][c1 - 'a'] = 1;
	}
	int N = strlen(s);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 26; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (a[j][s[i] - 'a'] == 0) {
				dp[i + 1][s[i] - 'a'] = max(dp[i + 1][s[i] - 'a'], dp[i][j] + 1);	
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans = max(ans, dp[N][i]);
	}
	printf("%d\n", N - ans);
	return 0;
}