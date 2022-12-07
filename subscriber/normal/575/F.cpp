/* -- ITMO UNIVERSITY 1 ---*/
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
#include <queue>

#define fs first
#define sc second
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

static inline unsigned long long rdtsc() { unsigned long long d; __asm__ __volatile__ ("rdtsc" : "=A" (d) ); return d; }

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1.01e9;
const dbl eps = 1e-9;
const int M = (int)1e9 + 7;
const int N = (int)3.22e5;

/* --- main part --- */

#define TASK "1"


const int maxn = (int)1e4 + 10;

ll d[maxn];
int x[maxn], xc = 0;
int l[maxn], r[maxn];

int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int n, X;
    scanf("%d%d", &n, &X);
    forn(i, n) scanf("%d%d", &l[i], &r[i]);
    x[xc++] = X;
    forn(i, n) x[xc++] = l[i], x[xc++] = r[i];
    sort(x, x + xc);
    xc = unique(x, x + xc) - x;
    X = lower_bound(x, x + xc, X) - x;
    forn(i, n)
    {
        l[i] = lower_bound(x, x + xc, l[i]) - x;
        r[i] = lower_bound(x, x + xc, r[i]) - x;
    }
    forn(i, xc) d[i] = 1e18;
    d[X] = 0;
    forn(j, n)
    {
        for (int i = 1; i < xc; ++i) d[i] = min(d[i], d[i - 1] + x[i] - x[i - 1]);
        for (int i = xc - 2; i >= 0; --i) d[i] = min(d[i], d[i + 1] + x[i + 1] - x[i]);
        forn(i, xc)
        {
            if (i < l[j]) d[i] += x[l[j]] - x[i];
            else if (i > r[j]) d[i] += x[i] - x[r[j]];
        }
    }
    ll res = 1e18;
    forn(i, xc) res = min(res, d[i]);
    printf("%I64d\n", res);

    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}