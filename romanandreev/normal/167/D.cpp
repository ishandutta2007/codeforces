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
const int md = (int)1e9 + 9;
int n, k;
pi p[1000000];
int kv, root;
int x[1000000];
int y[1000000];
int L[1000000];
int R[1000000];

int dp0[1000000];
int dp1[1000000];


void recalc(int v) {
	if (v == 0) return;
	dp0[v] = max(dp0[L[v]], dp1[L[v]]) + max(dp0[R[v]], dp1[R[v]]);
	dp1[v] = -1e9;
	if (L[v] > 0)
	dp1[v] = max(dp1[v], dp0[L[v]] + max(dp0[R[v]], dp1[R[v]]) + 1);
	if (R[v] > 0)
	dp1[v] = max(dp1[v], dp0[R[v]] + max(dp0[L[v]], dp1[L[v]]) + 1);
}
int mergee(int a, int b) {
	if (a == 0 || b == 0) return a + b;
	if (y[a] < y[b]) {
		L[b] = mergee(a, L[b]);
		recalc(b);
		return b;
	}
	R[a] = mergee(R[a], b);
	recalc(a);
	return a;
}
void split(int v, int X, int& lf, int&rg) {
	lf = 0;
	rg = 0;
	if (v == 0) return;
	int gg;
	if (x[v] <= X) {
		split(R[v], X, gg, rg);
		R[v] = gg;
		lf = v;
	} else {
		split(L[v], X, lf, gg);
		L[v] = gg;
		rg = v;
	}
	recalc(lf);
	recalc(rg);
}
//void dfs()
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
//		cerr<<p[i].x<<" "<<p[i].y<<endl;		
	}
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	for (int i = k; i < n; i++) {
		p[i].x = ((ll)A * p[i - 1].x + B) % md;
		p[i].y = ((ll)C * p[i - 1].y + D) % md;
//		cerr<<p[i].x<<" "<<p[i].y<<endl;
	}
	sort(p, p + n);
	root = 0;
	kv = 0;
	for (int i = 0; i < n; i++) {
		kv++;
		x[kv] = p[i].x;
		y[kv] = p[i].y;
		L[kv] = 0;
		R[kv] = 0;
		dp0[kv] = 0;
		dp1[kv] = -1e9;
		root = mergee(root, kv);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int l, r ,lf, md, rg;
		scanf("%d %d", &l, &r);
		split(root, r, md, rg);
		split(md, l - 1, lf, md);
		printf("%d\n", max(dp0[md], dp1[md]));
		lf = mergee(lf, md);
		root = mergee(lf, rg);
	}
	return 0;
}