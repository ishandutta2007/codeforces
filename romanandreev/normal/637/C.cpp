/**
 *    author:  enot.1.10, Vladimir Smykalov (enot.1.10@gmail.com)
 *    created: 13.03.2016 15:06:04       
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

const int inf = (int)1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

#define TASK "1"

const int N = 1010;

char s[N][10];

int dist(int i, int j)
{
    int r = 0;
    forn(k, 6) if (s[i][k] != s[j][k]) ++r;
    return r;
}

int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%s", s[i]);
    int d = 6;
    forn(i, n) forn(j, i) d = min(d, (dist(i, j) - 1) / 2);
    printf("%d\n", d);
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}