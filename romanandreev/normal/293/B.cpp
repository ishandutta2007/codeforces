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
int n, m, k;
int a[20][20];
int b[20][20];

int dp[20][20][12];
int go[20];
int was[20];
int og[20];

int used[20];

int ans = 0;
const int md = 1e9 + 7;
void bct(int x, int y) {
    if (x == n) {
        for (int i = 1; i <= k; i++) {
            go[i] = 0;
            og[i] = 0;
            used[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                used[a[i][j]] = 1;
                if (b[i][j] != 0) {
                    if (go[b[i][j]] == 0) {
                        go[b[i][j]] = a[i][j];                        
                    } else {
                        if (go[b[i][j]] != a[i][j]) {
                            return;
                        }
                    } 
                    if (og[a[i][j]] == 0) {
                        og[a[i][j]] = b[i][j];                        
                    } else {
                        if (og[a[i][j]] != b[i][j]) {
                            return;
                        }
                    } 
                }
            }
        }
          
        int c1 = 0;
        int c2 = 0;       
        for (int i = 1; i <= k; i++) {            
            if (used[i] != 0) {
                c1++;
            }
            if (og[i] != 0) c2++;
        }
        ll tk = 1;
        for (int i = 0; i < c1 - c2; i++) {
            tk = (tk * (k - c2 - i)) % md;
        }
        ans = (ans + tk) % md;
        return;
    }
    if (y == m) {
        bct(x + 1, 0);
        return;
    }
    for (int i = 1; i <= k; i++) {
        dp[x + 1][y + 1][i] = dp[x][y + 1][i] + dp[x + 1][y][i] - dp[x][y][i];
    }    
    bool was0 = false;
    for (int i = 1; i <= k; i++) if (dp[x + 1][y + 1][i] == 0) {
        if (was[i] == 0 && was0) {
            break;
        }
        a[x][y] = i;
        dp[x + 1][y + 1][i]++;
        was[i]++;
        bct(x, y + 1);
        dp[x + 1][y + 1][i]--;
        a[x][y] = 0;
        was[i]--;
        if (was[i] == 0) {
            was0 = true;
        }
    }
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d %d %d", &n, &m, &k);    
    if (n + m - 1 > k) {
        printf("%d\n", 0);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    bct(0, 0);
    cout<<ans<<endl;
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}