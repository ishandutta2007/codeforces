#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
// #define int ll

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int INF = (is_same<int, ll>::value ? 1e18L + 666 : 1e9L + 666);

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("filename");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> neighbors(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        neighbors[u] |= (1 << v);
        neighbors[v] |= (1 << u);
    }
    vector<int> dp(1 << n, INF);
    vector<pair<int, int>> prv(1 << n, {-1, -1});
    for (int msk = 0; msk < (1 << n); ++msk) {
        int m = (1 << n) - 1;
        for (int i = 0; i < n; ++i) {
            if (msk & (1 << i)) {
                m &= neighbors[i] | (1 << i);
            }
        }
        if ((m & msk) == msk) {
            dp[msk] = 0;
        }
    }
    for (int msk = 0; msk < (1 << n); ++msk) {
        for (int i = 0; i < n; ++i) {
            if (!(msk & (1 << i)))
                continue;
            if (cmin(dp[msk | neighbors[i]], dp[msk] + 1)) {
                prv[msk | neighbors[i]] = {msk, i};
            }
        }
    }
    cout << dp.back() << endl;
    int cur = (1 << n) - 1;
    vector<int> ans;
    while (cur != -1) {
        ans.pb(prv[cur].second);
        cur = prv[cur].first;
    }
    ans.kek();
    reverse(all(ans));
    for (auto &x : ans) {
        cout << x + 1 << " ";
    }
    cout << endl;
}