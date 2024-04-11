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

const int N = 1000111;

int n, m, s, d;

int a[N];
int pr[N];


int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    a[n++] = -1;
    sort(a, a + n);
    int gr = 0;
    int fr = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] >= gr) {
            puts("IMPOSSIBLE");
            return 0;
        }
        pr[i] = fr;
        if (i + 1 == n) break;
        if (a[i + 1] - a[i] - 2 >= s) {
            gr = a[i + 1] - 1 + d;
            fr = i;
        }
    }
    vector<pair<string, int> > out;
    if (m > a[n - 1] + 1) out.pb(mp("RUN", m - a[n - 1] - 1));
    int x = n - 1;
    while (x > 0) {
        int jp = a[pr[x] + 1] - 1;
        out.pb(mp("JUMP", a[x] + 1 - jp));
        out.pb(mp("RUN", jp - (a[pr[x]] + 1)));
        x = pr[x];    
    }
    reverse(out.begin(), out.end());
    for (int i = 0; i < out.size(); i++) {  
        cout << out[i].F << " " << out[i].S << endl;
    }

    
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}