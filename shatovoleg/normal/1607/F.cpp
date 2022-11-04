#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 3e18l + 666 : 1e9 + 666);
const ll INFll = 3e18l + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(ll a, ll b, int mod) {
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

void run();

// #define TASK "magic"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void solve();

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

const string s = "ULDR";
constexpr array<pair<short, short>, 4> moves = {{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};

pair<short, short> get_next(short x, short y, char c) {
    auto [dx, dy] = moves[find(all(s), c) - s.begin()];
    return {x + dx, y + dy};
}

int n, m;

bool check(short x, short y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    cin >> n >> m;
    vector<string> fld(n);
    for (auto& x : fld) {
        cin >> x;
    }
    vector<vector<int>> lens(n, vector<int>(m, 0));
    vector<pair<short, short>> stack;
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; ++j) {
            short x = i, y = j;
            while (check(x, y) && lens[x][y] == 0) {
                stack.emplace_back(x, y);
                lens[x][y] = -len(stack);
                tie(x, y) = get_next(x, y, fld[x][y]);
            }
            int cur = 0;
            if (!check(x, y) || lens[x][y] > 0) {
                if (check(x, y)) {
                    cur = lens[x][y];
                }
            } else {
                int ln = lens[x][y] + len(stack) + 1;
                for (int i = 0; i < ln; ++i) {
                    tie(x, y) = stack.back();
                    stack.kek();
                    lens[x][y] = ln;
                }
                cur = ln;
            }
            while (!stack.empty()) {
                tie(x, y) = stack.back();
                stack.kek();
                lens[x][y] = ++cur;
            }
        }
    }
    int mx = 0, r, c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (cmax(mx, lens[i][j])) {
                r = i;
                c = j;
            }
        }
    }
    cout << r + 1 << " " << c + 1 << " " << mx << "\n";
}