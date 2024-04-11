#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
int n, m, k;
int a[1000000];
int x[1000000];
int y[1000000];
int z[1000000];
int ff[1000000];
ll gg[1000000];


int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
		x[i]--, y[i]--;
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		ff[x]++;
		ff[y + 1]--;
	}
	ll tk = 0;
	for (int i = 0; i < m; i++) {
		tk += ff[i];
		gg[x[i]] += tk * z[i];
		gg[y[i] + 1] -= tk * z[i];
	}
	tk = 0;
	for (int i = 0; i < n; i++) {
		tk += gg[i];
		printf("%I64d%c", a[i] + tk, " \n"[i + 1 == n]);
	}
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}