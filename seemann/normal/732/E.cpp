#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 2e5 + 100;

struct comp {
    int x, n;
    bool operator < (const comp & o) const {
        if (x != o.x) {
            return x < o.x;
        }
        return n < o.n;
    }
};
struct socket {
    int x, d, n;
    bool operator < (const socket & o) const {
        if (x != o.x) {
            return x < o.x;
        }
        if (d != o.d) {
            return d > o.d;
        }
        return n < o.n;
    }
};
int anss[MAXN];
int ansc[MAXN];
bool used[MAXN];

int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<comp> comps(n);
    vector<socket> sockets;
    forn(i, n) {
        int p;
        cin >> p;
        comps[i] = {p, i};
    }
    forn(i, m) {
        int p;
        cin >> p;
        int j = 0;
        sockets.push_back({p, j, i});
        while (p > 1) { 
            p = (p + 1) / 2;
            j++;
            sockets.push_back({p, j, i});
        }
    }
    sort(comps.begin(), comps.end());
    sort(sockets.begin(), sockets.end());
    auto ci = comps.rbegin();
    auto si = sockets.rbegin();
    int ans1 = 0, ans2 = 0;
    forn(i, n)
        ansc[i] = -1;
    while (ci != comps.rend() && si != sockets.rend()) {
        if (used[si->n]) {
            si++;
        } else if (ci->x == si->x) {
            ans1++;
            ans2 += si->d;
            ansc[ci->n] = si->n;
            anss[si->n] = si->d;
            used[si->n] = true;
            ci++, si++;
        } else if (ci->x > si->x) {
            ci++;
        } else {
            si++;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
    forn(i, m) {
        cout << anss[i] << ' ';
    }
    cout << '\n';
    forn(i, n) {
        cout << ansc[i] + 1 << ' ';
    }
    cout << '\n';
    

    return 0;
}