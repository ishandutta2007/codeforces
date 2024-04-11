#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll high(vvi& tree, vi& val, ll& ans, int loc, int par) {
    ll res = val[loc];
    for (int nbr : tree[loc]) if (nbr != par) {
        res += max(0ll, high(tree, val, ans, nbr, loc));
    }
    ans = max(ans, res);
    return res;
}

ll count(vvi& tree, vi& val, const ll& ans, int &cnt, int loc, int par) {
    ll res = val[loc];
    for (int nbr : tree[loc]) if (nbr != par) {
        res += max(0ll, count(tree, val, ans, cnt, nbr, loc));
    }
    if (res == ans) {
        cnt++;
        res = 0;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi val(N);
    for (int i = 0; i < N; i++)
        cin >> val[i];

    vvi tree(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    ll ans = LLONG_MIN;
    high(tree, val, ans, 0, 0);

    int cnt = 0;
    count(tree, val, ans, cnt, 0, 0);

    cout << ans * cnt << " " << cnt << endl;

    return 0;
}