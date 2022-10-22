#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int getr(int v, vector<int>& root) {
    vector<int> path;
    while (root[v] != v) {
        path.push_back(v);
        v = root[v];
    }
    while (!path.empty()) {
        root[path.back()] = v;
        path.pop_back();
    }
    return v;
}

bool fuse(int u, int v, vector<int>& root, vector<int>& siz, vector<bool>& incl) {
    u = getr(u, root);
    v = getr(v, root);
    if (u == v) {
        return false;
    }
    if (incl[u] && incl[v]) {
        return false;
    }
    root[u] = v;
    siz[v] += siz[u];
    if (incl[u]) {
        incl[v] = true;
    }
    return true;
}

ll todeg(ll x, ll d) {
    if (d == 0) {
        return 1;
    }
    ll ans = todeg(x, d / 2);
    ans = (ans * ans) % MOD;
    if (d % 2 == 1) {
        ans = (ans * x) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> m >> n;
    vector<int> root(n);
    vector<int> siz(n, 1);
    for (int i = 0; i < n; ++i) {
        root[i] = i;
    }
    vector<bool> incl(n, false);

    vector<int> ssh;
    for (int i = 0; i < m; ++i) {
        int k, u, v;
        cin >> k >> u;
        --u;
        if (k == 1) {
            if (!incl[getr(u, root)]) {
                incl[getr(u, root)] = true;
                ssh.push_back(i + 1);
            }
        }
        else {
            cin >> v;
            --v;
            if (fuse(u, v, root, siz, incl)) {
                ssh.push_back(i + 1);
            }
        }
    }

    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        if (root[i] != i) {
            continue;
        }
        //cout << i << " " << incl[i] << " " << siz[i] << "\n";
        if (incl[i]) {
            ans = (ans * todeg(2, siz[i])) % MOD;
        }
        else {
            ans = (ans * todeg(2, siz[i] - 1)) % MOD;
        }
    }

    cout << ans << " " << ssh.size() << "\n";
    for (int i = 0; i < ssh.size(); ++i) {
        cout << ssh[i] << " ";
    }
}