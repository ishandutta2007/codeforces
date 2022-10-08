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
int n, k;
int a[100000];
int b[100000];
int p[100000];
int wh[100000];


int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i++) {
		a[i] = 1;
	}
	a[n] = 0;
	for (int i = 0; i < k; i++) {
		int mx = 0;
		for (int j = 0; j <= n; j++) {
			wh[j] = -1;
		}
		for (int j = 1; j <= n; j++) {
			wh[a[j]] = j;
			mx = max(mx, a[j]);
		}
		for (int j = 1; j <= n; j++) {
			if (a[j] + mx <= n - j) {
				b[j] = a[j] + mx;
				p[j] = wh[mx];				
			} else {	
				b[j] = n - j;
				p[j] = wh[n - j - a[j]];
			}
		}
		for (int j = 1; j <= n; j++) {
			printf("%d%c", p[j], " \n"[j == n]);
			a[j] = b[j];
		}
	}
	for (int j = 1; j <= n; j++) {
		assert(a[j] == n - j);
	}
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}