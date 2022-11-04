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

// #define TASK "codes"

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

constexpr ll mod = 1e9 + 7;

bool is_ancestor(ll u, ll v) {
    while (v > u) {
        v >>= 1;
    }
    return v == u;
}

struct Node {
    void add(ll idx, int clr, ll v = 1) {
        if (v == idx) {
            color = clr;
            return;
        }
        int dir = 0;
        if (is_ancestor(2 * v + 1, idx)) {
            dir = 1;
        } else {
            assert(is_ancestor(2 * v, idx));
        }
        if (!childs[dir]) {
            childs[dir] = make_unique<Node>();
        }
        childs[dir]->add(idx, clr, 2 * v + dir);
    }

    unique_ptr<Node> childs[2];
    int color = -1;
};

vector<ll> cnts;

void init(int k) {
    cnts.resize(k);
    cnts[0] = 1;
    for (int i = 1; i < k; ++i) {
        cnts[i] = cnts[i - 1] * cnts[i - 1] % mod * 16 % mod;
    }
}

constexpr std::size_t color_count = 6;

array<ll, color_count> dfs(const unique_ptr<Node>& v, int d) {
    if (!v) {
        array<ll, color_count> res;
        fill(all(res), cnts[d]);
        return res;
    }
    if (d == 0) {
        std::array<ll, color_count> res;
        fill(all(res), 0);
        res[v->color] = cnts[0];
        return res;
    }
    auto left = dfs(v->childs[0], d - 1);
    auto right = dfs(v->childs[1], d - 1);
    ll sum_left = accumulate(all(left), 0ll) % mod;
    ll sum_right = accumulate(all(right), 0ll) % mod;
    array<ll, color_count> res;
    fill(all(res), 0);
    for (size_t clr = 0; clr < color_count; ++clr) {
        if (v->color != -1 && v->color != int(clr)) continue;
        ll lft = sum_left - left[clr] - left[clr ^ 1] + 2 * mod;
        lft %= mod;
        ll rght = sum_right - right[clr] - right[clr ^ 1] + 2 * mod;
        rght %= mod;
        res[clr] = lft * rght % mod;
    }
    return res;
}

void run() {
    const array<string, color_count> colors = {"white"s, "yellow"s, "green"s, "blue"s, "red"s, "orange"s};

    int k, n;
    cin >> k >> n;
    init(k);

    unique_ptr<Node> root = make_unique<Node>();
    for (int i = 0; i < n; ++i) {
        ll v;
        string clr;
        cin >> v >> clr;
        int clr_id = int(find(all(colors), clr) - colors.begin());
        root->add(v, clr_id);
    }
    array<ll, color_count> dp = dfs(root, k - 1);
    ll sm = accumulate(all(dp), 0ll);
    cout << sm % mod << endl;
}