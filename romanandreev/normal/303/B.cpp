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
#define y1 y1_fdiosdhfk
using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
ll n, m, x, y, a, b;
ld x1, y1, x2, y2;

int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    cin>>n>>m>>x>>y>>a>>b;
    ll g = __gcd(a, b);
    a /= g;
    b /= g;                                                               
    ll d = min(n / a, m / b);
    a = a * d;
    b = b * d;
    ld X1 = a * 0.5;
    ld X2 = n - a * 0.5;
    ld Y1 = b * 0.5;
    ld Y2 = m - b * 0.5;
    ld CX = max(X1, min(X2, (ld)x));
    ld CY = max(Y1, min(Y2, (ld)y));
    x1 = CX - a * 0.5;
    x2 = CX + a * 0.5;
    y1 = CY - b * 0.5;
    y2 = CY + b * 0.5;
    if (fabs(round(x1) - x1) > 0.1) {
        x1 -= 0.5;
        x2 -= 0.5;
    }
    if (fabs(round(y1) - y1) > 0.1) {
        y1 -= 0.5;
        y2 -= 0.5;
    }
    printf("%.0lf %.0lf %.0lf %.0lf\n", (double) x1, (double)y1, (double)x2, (double)y2);

    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}