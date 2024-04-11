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
typedef unsigned int ui;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
int n, k;
ui a[1000000];
ui b[1000000];
int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		ui x1, x2, x3, x4; 		
		scanf("%u.%u.%u.%u", &x1, &x2, &x3, &x4);
		a[i] = (x1 << 24) + (x2 << 16)  + (x3 << 8) + x4;
	}
	sort(a, a + n);
	for (int i = 1; i < 32; i++) {
		ui msk = 0;
		for (int j = 0; j < 32; j++) {
			msk = msk * 2 + (j < i);
		}
		for (int j = 0; j < n; j++) {
			b[j] = a[j] & msk;
		}
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (j == 0 || b[j] != b[j - 1]) {
				cnt++;
			}
		}
		if (cnt == k) {
			printf("%u.%u.%u.%u\n", (msk >> 24) & (255), (msk >> 16) & (255), (msk >> 8) & (255), (msk >> 0) & (255));
			return 0;
		}
	}
	printf("-1\n");
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}