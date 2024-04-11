#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;

inline void start() {
#ifdef BOKU_NO_PICO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#endif
}

typedef struct Node* pNode;
struct Node {
    pNode child_left, child_right;
    ll left, right;
    ll value;

    Node(ll left, ll right)
        : left(left), right(right) {
        value = 0;
        child_left = child_right = nullptr;
    }
};

pNode build(ll left, ll right, vector<ll>& a) {
    pNode root = new Node(left, right);
    if (right - left == 1) {
        root->value = a[left];
        return root;
    }
    root->child_left = build(left, (left + right) / 2, a);
    root->child_right = build((left + right) / 2, right, a);
    root->value = min(root->child_left->value, root->child_right->value);
    return root;
}

ll get(pNode root, ll left, ll right) {
    if (root->left >= right || root->right <= left) {
        return 1e17;
    }
    if (root->left >= left && root->right <= right) {
        return root->value;
    }
    return min(get(root->child_right, left, right), get(root->child_left, left, right));
}

inline void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> p(n);
    vector<ll> a(m);
    vector<ll> ind(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        ind[p[i]] = i;
    }
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<ll> id(n, m);
    vector<vector<ll>> dp(20, vector<ll>(m + 1));
    dp[0][m] = m;
    for (ll i = m - 1; i >= 0; --i) {
        dp[0][i] = id[p[(ind[a[i]] + 1) % n]];
        id[a[i]] = i;
    }
    for (ll i = 1; i < 20; ++i) {
        for (ll j = 0; j <= m; ++j) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    for (ll i = 0; i < m; ++i) {
        ll v = i;
        ll x = n - 1;
        for (ll j = 19; j >= 0; --j) {
            if (x >= (1 << j)) {
                x -= (1 << j);
                v = dp[j][v];
            }
        }
        a[i] = v;
    }
    pNode root = build(0, m, a);
    string res;
    for (ll i = 0; i < q; ++i) {
        ll left, right;
        cin >> left >> right;
        if (get(root, left - 1, right) < right) {
            res.push_back('1');
        }
        else {
            res.push_back('0');
        }
    }
    cout << res << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}