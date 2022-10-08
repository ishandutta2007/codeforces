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

int c1;
int n, m, md;
vector<int> r[1000000];
vi vv;
int was[1000000];
void dfs(int v) {
	if (was[v] == 1) return;
	c1++;
	was[v] = 1;
	for (int i = 0; i < sz(r[v]); i++) {
		int e = r[v][i];
		dfs(e);
	}
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d %d", &n, &m, &md);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		r[x].pb(y);
		r[y].pb(x);
	}
	for (int i = 0; i < n; i++) if (was[i] == 0) {
		c1 = 0;
		dfs(i);
		vv.pb(c1);
	}
	int T = sz(vv);
	if (T == 1) {
		cout<<1 % md<<endl;
		return 0;
	}
	ll ans = 1;
	for (int i = 0; i < T; i++) {
		ans = (ans * vv[i]) % md;
	}
	
	ll sum = 0;
	for (int i = 0; i < T; i++) {
		sum += vv[i];
	}
	sum = sum % md;
	for (int i = 0; i < T - 2; i++) {
		ans = (ans * sum) % md;
	}

	cout<<ans % md<<endl;
	return 0;
}