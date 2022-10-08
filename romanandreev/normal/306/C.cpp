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
const int md = 1e9 + 9;
int dp[4020][4020];
int n, w, b;
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    cin>>n>>w>>b;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= max(w, b); j++) {
            /*for (int k = 1; k <= j; k++) {
                dp[i][j] += dp[i - 1][j - k];
            } */
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % md;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        ll add = (((ll)dp[i][b] * dp[n - i][w]) % md * (n - i - 1)) % md;
        ans = (ans + add) % md;
    }
    for (int i = 1; i <= w; i++) {
        ans = (ans * i) % md;
    }
    for (int i = 1; i <= b; i++) {
        ans = (ans * i) % md;
    }
    cout<<ans<<endl;
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}