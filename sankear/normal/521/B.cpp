#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <complex>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int MOD = int(1e9) + 9;

set<pair<int, pii> > can;
map<pii, int> points;

inline int get_cnt(pii p) {
    if (points.find(p) == points.end()) {
        return -1;
    }
    int res = 0;
    for (int i = -1; i <= 1; ++i) {
        if (points.find(mp(p.fs + i, p.sc - 1)) != points.end()) {
            ++res;
        }
    }
    return res;
}

inline bool check(pii p) {
    if (points.find(p) == points.end()) {
        return false;
    }
    for (int i = -1; i <= 1; ++i) {
        if (get_cnt(mp(p.fs + i, p.sc + 1)) == 1) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        points[mp(x, y)] = i;
    }
    for (auto it = points.begin(); it != points.end(); ++it) {
        if (check(it->fs)) {
            can.insert(mp(it->sc, it->fs));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        assert(sz(can) > 0);
        pii del;
        if (i % 2 == 0) {
            auto it = can.end();
            for (;;) {
                it = can.end();
                --it;
                if (!check(it->sc)) {
                    can.erase(it);
                    assert(sz(can) > 0);
                    continue;
                }
                break;
            }
            del = it->sc;
            ans = (1LL * ans * n + it->fs) % MOD;
            can.erase(it);
        } else {
            for (;;) {
                if (!check(can.begin()->sc)) {
                    can.erase(can.begin());
                    assert(sz(can) > 0);
                    continue;
                }
                break;
            }
            del = can.begin()->sc;
            ans = (1LL * ans * n + can.begin()->fs) % MOD;
            can.erase(can.begin());
        }
        points.erase(del);
        for (int j = -1; j <= 1; ++j) {
            pii p(del.fs + j, del.sc - 1);
            if (check(p)) {
                can.insert(mp(points[p], p));
            }
        }
    }
    cout << ans << endl;
    return 0;
}