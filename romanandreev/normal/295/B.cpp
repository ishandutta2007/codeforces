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
int a[1000][1000];
int d[1000][1000];
int p[1000];
ll gg[1000];
int n;
int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	reverse(p, p + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = a[i][j];
		}
	}
	for (int kk = 0; kk < n; kk++) {
		int k = p[kk];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
		gg[kk] = 0;
		for (int i = 0; i <= kk; i++) {
			for (int j = 0; j <= kk; j++) {
				gg[kk] += d[p[i]][p[j]];
		    }
		}
	}
	reverse(gg, gg + n);
	for (int i = 0; i < n; i++) {
		printf("%I64d%c", gg[i], " \n"[i == n - 1]);
	}
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}