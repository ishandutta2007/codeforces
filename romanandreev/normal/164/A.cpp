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
int n, m;
int tp[1000000];
vector<int> r[1000000];
vector<int> ro[1000000];
int was1[1000000];
int was2[1000000];
void dfs1(int v) {
	was1[v] = 1;
	if (tp[v] == 1) return;
	for (int i = 0; i < sz(ro[v]); i++) {
		int e = ro[v][i];
		if (was1[e] == 0) {
			dfs1(e);
		}
	}
}
void dfs2(int v) {
	was2[v] = 1;
	for (int i = 0; i < sz(r[v]); i++) {
		int e = r[v][i];
		if (was2[e] == 0 && tp[e] != 1) {
			dfs2(e);
		}
	}
}

int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tp[i]);
	}
	for (int  i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		r[x].pb(y);
		ro[y].pb(x);
	}
	for (int i = 0; i < n; i++) if (was1[i] == 0 && tp[i] == 2){
		dfs1(i);
	}
	for (int i = 0; i < n; i++) if (was2[i] == 0 && tp[i] == 1){
		dfs2(i);
	}
	for (int i = 0; i < n; i++) {
//		cerr<<was1[i]<<" "<<was2[i]<<endl;
		if (was1[i] && was2[i]) printf("1\n");
		else printf("0\n");
	}
	return 0;
}