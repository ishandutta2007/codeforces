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
#include <queue>
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
int a[200100];
int good[200100];

int g[2001000];
int dp[2001000];
int bc[2001000];
vi st[2001000];
vi en[2001000];

struct my_int {
    int i;
    my_int() {
    }
    my_int(int i):i(i) {
    }
};
bool operator < (my_int x, my_int y) {
    if (a[x.i] != a[y.i]) return a[x.i] > a[y.i];
    return x.i < y.i;
}

void bct(int x) {
    if (x == 0) return;
    if (bc[x] == -1) {
        bct(x - 1);
        return;
    }
    bct(a[bc[x]] - 1);
    good[bc[x]] = 1;
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int l;
        scanf("%d %d", &a[i], &l);
        g[a[i]]++;
        g[a[i] + l]--;
        st[a[i]].pb(i);
        en[a[i] + l - 1].pb(i);
    }
    for (int i = 1; i <= n + 1; i++) {
        g[i] = g[i - 1] + g[i];
    }
    dp[0] = 0;
    priority_queue<my_int> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < sz(st[i]); j++) {
            s.push(st[i][j]);
            good[st[i][j]] = 1;
        }
        if (g[i] == 0) {
            dp[i] = dp[i - 1];
            bc[i] = -1;
        } else {
            my_int m;
            while (1) {
                m = s.top();
                if (good[m.i] == 0) {
                    s.pop();
                    continue;
                } else {
                    break;
                }
            }
            dp[i] = dp[a[m.i] - 1] + 1;
            bc[i] = m.i;
        }
        for (int j = 0; j < sz(en[i]); j++) {
            good[en[i][j]] = 0;
        }
    }
    memset(good, 0, sizeof(good));
    bct(n);
    printf("%d\n", m - dp[n]);
    for (int i = 0; i < m; i++) {
        if (good[i] == 0) {
            printf("%d ", i + 1);
        }
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}