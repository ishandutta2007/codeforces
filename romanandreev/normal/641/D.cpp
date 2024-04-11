/**
 *    author:  [itmo] enot.1.10
 *    created: 24.04.2016 19:55:45       
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

const int N = 1e5 + 10;

dbl mint[N];
dbl maxt[N];

dbl p[N];
dbl q[N];


int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%lf", &maxt[i + 1]);
    forn(i, n) scanf("%lf", &mint[i + 1]);

    for (int i = 1; i <= n; ++i)
    {
        dbl sum = mint[i] + maxt[i] + p[i - 1] + q[i - 1];
        dbl prod = maxt[i] + p[i - 1] * q[i - 1];
        dbl A = 1;
        dbl B = -sum;
        dbl C = prod;
        dbl D = max(0., B * B - 4 * A * C);
        dbl x1 = (-B - sqrt(D)) / 2;
        dbl x2 = (-B + sqrt(D)) / 2;
        p[i] = x1;
        q[i] = x2;
    }

    for (int i = 1; i <= n; ++i) printf("%.10f%c", p[i] - p[i - 1], " \n"[i == n]);
    for (int i = 1; i <= n; ++i) printf("%.10f%c", q[i] - q[i - 1], " \n"[i == n]);

    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}