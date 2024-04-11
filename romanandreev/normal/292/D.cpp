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
int n, m;
int x[100000];
int y[100000];
int up[3][1000];
vector<int> lf[20000];
vector<int> rg[20000];

int go(int t, int x) {
    if (up[t][x] == x) return x;
    return up[t][x] = go(t, up[t][x]);
}
bool merge(int t, int x, int y) {
    x = go(t, x);
    y = go(t, y);
    if (x != y) {
        up[t][x] = y;
        return true;
    }
    return false;
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x[i], &y[i]);
        x[i]--, y[i]--;
    }
    for (int i = 0; i < n; i++) {
        up[0][i] = i;
        up[1][i] = i;
    }    
    for (int i = 1; i <= m; i++) {
        lf[i] = lf[i - 1]; 
        if (merge(0, x[i], y[i])) {
            lf[i].pb(i);
        }
    }
    for (int i = m; i >= 1; i--) {
        rg[i] = rg[i + 1]; 
        if (merge(1, x[i], y[i])) {
            rg[i].pb(i);
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        for (int j = 0; j < n; j++) {
            up[2][j] = j;
        }
        int cnt = n;
        for (int j = 0; j < sz(lf[l - 1]); j++) {
            if (merge(2, x[lf[l - 1][j]], y[lf[l - 1][j]])) {
                cnt--;
            }
        }
        for (int j = 0; j < sz(rg[r + 1]); j++) {
            if (merge(2, x[rg[r + 1][j]], y[rg[r + 1][j]])) {
                cnt--;
            }
        }
        printf("%d\n", cnt);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}