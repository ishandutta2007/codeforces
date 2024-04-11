// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef struct Node* pNode;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

struct Node {
    pNode child_left, child_right;
    ll left, right;
    ll cnt, sum;

    Node(ll left, ll right)
        : left(left), right(right) {
        child_left = child_right = nullptr;
        cnt = sum = 0;
    }
};

pNode build(ll left, ll right) {
    pNode root = new Node(left, right);
    if (right - left == 1) {
        return root;
    }
    root->child_left = build(left, (left + right) / 2);
    root->child_right = build((left + right) / 2, right);
    return root;
}

void add(pNode root, ll x, ll t) {
    if (root->left >= t + 1 || root->right <= t) {
        return;
    }
    if (root->right - root->left == 1) {
        root->cnt += x;
        root->sum += x * t;
        return;
    }
    add(root->child_left, x, t);
    add(root->child_right, x, t);
    root->cnt = root->child_left->cnt + root->child_right->cnt;
    root->sum = root->child_left->sum + root->child_right->sum;
}

ll get(pNode root, ll& t) {
    if (root->sum <= t) {
        t -= root->sum;
        return root->cnt;
    }
    if (root->left > t || root->cnt == 0) {
        return 0;
    }
    if (root->right - root->left == 1) {
        ll res = t / root->left;
        t %= root->left;
        return res;
    }
    return get(root->child_left, t) + get(root->child_right, t);
}

vector<vector<pair<ll, ll>>> tree;
vector<ll> dp;
vector<ll> x;
vector<ll> t;
pNode root = nullptr;

void dfs(ll v, ll T) {
    add(root, x[v], t[v]);
    ll t_ = T;
    dp[v] = get(root, t_);
    for (auto u : tree[v]) {
        dfs(u.first, T - u.second);
    }
    ll mx1 = -1, mx2 = -1;
    for (auto u : tree[v]) {
        if (mx1 < dp[u.first]) {
            mx2 = mx1;
            mx1 = dp[u.first];
        }
        else if (mx2 < dp[u.first]) {
            mx2 = dp[u.first];
        }
    }
    dp[v] = max(dp[v], mx2);
    if (v == 0) {
        dp[v] = max(dp[v], mx1);
    }
    add(root, -x[v], t[v]);
}

inline void solve() {
    root = build(1, 1'000'666);
    ll n, T;
    cin >> n >> T;
    x.resize(n);
    t.resize(n);
    dp.resize(n);
    tree.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (ll i = 1; i < n; ++i) {
        ll p, y;
        cin >> p >> y;
        tree[p - 1].emplace_back(i, 2 * y);
    }
    dfs(0, T);
    cout << dp[0] << endl;
}

int main() {
    start();
    solve();
    return 0;
}