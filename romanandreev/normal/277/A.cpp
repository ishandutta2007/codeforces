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
int a[210][210];
int was[210];
void dfs(int v) {
	was[v] = 1;
	for (int i = 0; i < n + m; i++) if (a[v][i] == 1 && was[i] == 0) {
		dfs(i);
	} 
} 
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	scanf("%d %d", &n, &m);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int k, x;
		scanf("%d", &k);
		cnt += k;
		for (int j = 0; j < k; j++) {
			scanf("%d", &x);
			x--;
			a[i][x + n] = 1;			
			a[x + n][i] = 1; 
		}
	}
	int kk = 0;
	for (int i = 0; i < n; i++) {
		if (was[i] == 0) {
			dfs(i);
			kk++;
		}
	}
	if (cnt == 0) 
		cout<<n<<endl;
	else
		cout<<kk - 1<<endl;
	return 0;
}