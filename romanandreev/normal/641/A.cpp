/**
 *    author:  [itmo] enot.1.10
 *    created: 24.04.2016 19:34:10       
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

const int N = 2e5 + 10;

int a[N];
char s[N];
int b[N];

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    forn(i, n) scanf("%d", a + i);
    int x = 0;
    while (0 <= x && x < n && !b[x])
    {
        b[x] = 1;
        if (s[x] == '>') x += a[x];
        else x -= a[x];
    }
    if (0 <= x && x < n) printf("INFINITE\n");        
    else printf("FINITE\n");
        
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}