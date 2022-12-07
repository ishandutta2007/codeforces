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


int n;
string s[1111];

int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = 6;
    for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) {
        int t = 0;
        for (int k = 0; k < 6; k++) if (s[i][k] != s[j][k]) t++;
        ans = min(ans, (t - 1) / 2);
    }
    cout << ans << endl;
    
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}