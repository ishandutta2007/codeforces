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


#define TASK "a"
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    int mnx = 1e9;
    int mxx = -1e9;
    int mny = 1e9;
    int mxy = -1e9;

	ll s = 0;
    for (int i = 0; i < n; i++) {
    	int x1, y1, x2, y2;
    	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    	s += (ll)(x2 - x1) * (y2 - y1);
    	mnx = min(mnx, x1);
    	mxx = max(mxx, x2);
    	mny = min(mny, y1);
    	mxy = max(mxy, y2);
    }
    if (mxx - mnx == mxy - mny && (ll)(mxy - mny) * (mxy - mny) == s) {
    	printf("YES\n");
    } else {
    	printf("NO\n");
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}