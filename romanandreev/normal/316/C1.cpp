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
int dp[81][81][81][81];
int n, m;
int a[81][81];
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            for (int i1 = i; i1 < n; i1++) {
                for (int j1 = j; j1 < m; j1++) {
//                    if (((i1 - i + 1) * (j1 - j + 1)) % 2 != 0) {
                        dp[i][j][i1][j1] = 1e9;
  //                  }
                    if (((i1 - i + 1) * (j1 - j + 1)) == 2) {
                        if (a[i][j] == a[i1][j1]) {
                            dp[i][j][i1][j1] = 0;
                        } else {
                            dp[i][j][i1][j1] = 1;
                        }
                    }
                    for (int di = i; di < i1; di++) {
                        dp[i][j][i1][j1] = min(dp[i][j][i1][j1], dp[i][j][di][j1] + dp[di + 1][j][i1][j1]);
                    }
                    for (int dj = j; dj < j1; dj++) {
                        dp[i][j][i1][j1] = min(dp[i][j][i1][j1], dp[i][j][i1][dj] + dp[i][dj + 1][i1][j1]);
                    }
                }
            }
        }
    }
    cout<<dp[0][0][n - 1][m - 1]<<endl;
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}