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
typedef double ld;
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

const int sh = 1<<18;
int n ,m, c;
int x[sh];
int p[sh];
ld a[sh];
vector<ld> al[2 * sh + 10];
vector<ld> ar[2 * sh + 10];
ld ans[2 * sh + 10];
ld s[sh];
const ld eps = 1e-6;
/*ld get2(int x, int y) {
	ld ans = 0;
	for (int i = x; i <= y; i++) {
		for (int j = i; j <= y; j++) {
			ans = max(ans, s[j] - s[i - 1]);
		}
	}
	return ans;
}*/
ld get(int v,int l, int r, int ll, int rr, int fl) {
	if (ll > r || l > rr) return 0;
	if (l >= ll && r <= rr && fl == 0) {
		return ans[v];
	}
	ld tk = 0;
	int md = (l + r) /2;
	int l1 = max(l, ll);
	int r1 = min(md, rr);
	int l2 = max(md + 1, ll);
	int r2 = min(r, rr);
	if (r1 == md && l2 == md + 1) {
		tk = max(tk, al[v * 2 + 1][r2 - md] + ar[v * 2][md + 1 - l1]);
	}
	return max(tk, max(get(v * 2, l, md, ll, rr, 0), 
					   get(v * 2 + 1, md + 1, r, ll, rr, 0)));
}
void calc(int v, int l, int r) {
//	cerr<<v<<" "<<l<<" "<<r<<endl;
	al[v].pb(0);
	for (int i = l; i <= r; i++) {
		al[v].pb(max(al[v][sz(al[v]) - 1], s[i] - s[l - 1]));
	}
	ar[v].pb(0);
	for (int i = r; i >= l; i--) {
		ar[v].pb(max(ar[v][sz(ar[v]) - 1], s[r] - s[i - 1]));
	}
	ans[v] = 0;
	if (l == r) {
		ans[v] = max(ans[v], a[l]);
	 	return;
	}
	calc(v * 2, l, (l + r) / 2);
	calc(v * 2 + 1, (l + r) / 2 + 1, r);
	ans[v] = get(v, l, r, l, r, 1);
	//assert(fabs(ans[v] - get2(l , r)) < eps);
}

int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	s[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &p[i]);
		a[i + 1] = (x[i + 1] - x[i])/2. - p[i]/100. * c;
		s[i + 1] = s[i] + a[i + 1];
	} 
	calc(1, 1, sh);
	ld A = 0;
	for (int it = 0; it < m; it++) {
		int x, y;
		scanf("%d %d", &x, &y);
		y--;
		A += get(1, 1, sh, x, y, 0);
//		A += get2(x, y);
	}
	printf("%.18lf\n", (double)A);
//	while(1);
	return 0;
}