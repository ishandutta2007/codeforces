/**
 *    author:  [itmo] enot.1.10
 *    created: 28.03.2016 19:37:02       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */



int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n, d, h;
    scanf("%d%d%d", &n, &d, &h);
    if (d > 2 * h) return puts("-1"), 0;
    if (n == 2)
    {
        printf("1 2\n");
        return 0;
    }
    if (d == 1) return puts("-1"), 0;
    for (int i = 1; i <= h; ++i) printf("%d %d\n", i, i + 1);
    int j = 1;
    for (int i = h + 2; i <= d + 1; ++i)
    {
        printf("%d %d\n", j, i);
        j = i;
    }
    for (int i = d + 2; i <= n; ++i) printf("%d %d\n", h, i);
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}