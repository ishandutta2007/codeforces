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
int go[10000];
int pr[10000];
int r[10000];

vi ls;
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int n, x;
    scanf("%d %d", &n, &x);
    x--;
    int ST = 0;
    for (int i = 0; i < n; i++) {
        go[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
        pr[i]--;
        if (pr[i] != -1) {
            go[pr[i]] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (pr[i] == -1) {
            int tk = i;
            int cnt = 0;
            bool ff = true;
            while (tk != -1) {
                if (tk == x) {
                    ff = false;
                    ST = cnt;
                }
                cnt++;
                tk = go[tk];
            }
            if (ff)
            ls.pb(cnt);
        }
    }
    r[0] = 1;
    for (int i = 0; i < sz(ls); i++) {
        for (int j = n; j >= 0; j--) if (r[j] == 1) {
            r[j + ls[i]] = 1;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (r[i] == 1) {
            printf("%d\n", i + ST + 1);
        }
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}