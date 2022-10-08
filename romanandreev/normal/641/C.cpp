/**
 *    author:  [itmo] enot.1.10
 *    created: 24.04.2016 19:40:21       
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

const int N = 1e6 + 10;

int a[N];


int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int x = 0;
    int y = 1;
    int n, q;
    scanf("%d%d", &n, &q);
    forn(_, q)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int s;
            scanf("%d", &s);
            s = -s;
            if (s < 0) s += n;
            if (s % 2 == 0)
            {
                x = (x + s + n) % n;
                y = (y + s + n) % n;
            }
            else
            {
                int x2 = (y + (s - 1)) % n;
                int y2 = (x + (s + 1)) % n;
                x = x2, y = y2;
            }
        }
        else
        {
            swap(x, y);
        }
    }
    a[0] = x;
    a[1] = y;
    for (int i = 2; i < n; ++i) a[i] = (a[i - 2] + 2) % n;

    forn(i, n) printf("%d%c", a[i] + 1, " \n"[i + 1 == n]);
                
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}