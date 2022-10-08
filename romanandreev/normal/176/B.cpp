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
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
const int md = 1e9 + 7;
vi dp;
string a, b;
int k, n;
int ans;
vi calc(int k, int n) {
	vi dp(n, 0);
	if (k == 0) {
		dp[0] = 1;
		return dp;
	}
	vi dp1 = calc(k / 2, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[(i + j) % n] = (dp[(i + j) % n] + (ll)dp1[i] * dp1[j]) % md;
		}
	}
	if (k % 2 == 0) {
		return dp;
	}
	dp1 = dp;
	for (int i = 0; i < n; i++) {
		dp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[(i + j) % n] = (dp[(i + j) % n] + (ll)dp1[i]) % md;
		}
	}
	return dp;
}
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	cin>>a>>b>>k;
	if (sz(a) != sz(b)) {
		cout<<0<<endl;
		return 0;
	}
	n = sz(a);
	ans = 0;
	dp = calc(k, n);
	for (int i = 0; i < n; i++) {
		bool can = true;
		for (int j = 0; j < n; j++) {
			if (a[(i + j) % n] != b[j]) {
				can = false;
				break;
			}
		}
		if (can) {
			ans = (ans + dp[i]) % md;
		}
	}
	cout<<ans<<endl;
	return 0;
}