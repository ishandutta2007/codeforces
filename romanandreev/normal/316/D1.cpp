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
ll dp[1000][1000];
ll cnk[1000][1000];
ll f[1000];
const int md = (int)1e9 + 7;
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        cnk[i][0] = 1;
        f[i] = (i == 0) ? 1 : ((ll)f[i - 1] * i) % md;
        for (int j = 1; j <= i; j++) {
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % md;
        }
    }
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            c1++;
        } else {
            c2++;
        }
    }
    for (int i = 0; i <= c1; i++) {
        for (int j = 0; j <= c2; j++) {
            if (i + j <= 1) {
                dp[i][j] = 1;
                continue;
            }
            if (i > 0) {
                for (int i1 = 0; i1 + 1 <= min(2, i); i1++) {
                    for (int j1 = 0; j1 <= j; j1++) {
                        if (i1 == 0) {
                            dp[i][j] = (dp[i][j] + (cnk[j][j1] * f[j1]) % md * dp[i - 1][j - j1]) % md;
  //                          if (dp[i][j] < 0) assert(1 == 2);
  //                          cerr<<cnk[j][j1] * f[j1] * dp[i - 1][j - j1]<<endl;
                        } else {
                            dp[i][j] = (dp[i][j] + ((j1 + 1) * cnk[i - 1][i1]) % md * (((cnk[j][j1] * f[j1]) % md * dp[i - 2][j - j1]) % md)) % md;
//                            if (dp[i][j] < 0) assert(1 == 3);
//                            cerr<<2 * cnk[i - 1][i1] * cnk[j][j1] * f[j1] * dp[i - 2][j - j1]<<endl;
                        }
                    }
                }

           //     cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            } else {
                dp[i][j] = f[j];
            }
        }
    }
    cout<<dp[c1][c2]<<endl;
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}