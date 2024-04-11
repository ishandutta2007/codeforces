#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = (ll)1e18 + 41;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> dp(k + 1, 0);
    vector<ll> maxUseless(k + 1, -INF);

    vector<vector<ll>> prefs(n);

    for (int i = 0; i < n; i++) {
        ll sum = 0;
        int sz; cin >> sz;
        vector<pair<int, ll>> pref;
        for (int j = 0; j < sz; j++) {
            int x; cin >> x; sum += x;
            if (j + 1 <= k)
                prefs[i].push_back(sum);
        }
    }

    mt19937 rnd(3431);
    shuffle(prefs.begin(), prefs.end(), rnd);

    for (int i = 0; i < n; i++) {
        vector<pair<int, ll>> a;
        const auto &pp = prefs[i];
        for (int j = 0; j < (int)pp.size(); j++) if (pp[j] > maxUseless[j + 1]) {
            a.emplace_back(j + 1, pp[j]);
        }
        vector<bool> isA(a.size(), false);

        for (int pos = k; pos > 0; pos--) {
            ll oldDp = dp[pos];
            for (int j = 0; j < (int)a.size(); j++) {
                int len = a[j].first;
                if (pos < len) continue;
                ll val = a[j].second;
                if (oldDp < dp[pos - len] + val) isA[j] = true;
                if (dp[pos] < dp[pos - len] + val) dp[pos] = dp[pos - len] + val;
            }
        }

        for (int j = 0; j < (int)a.size(); j++) {
            if (!isA[j]) {
                maxUseless[a[j].first] = max(maxUseless[a[j].first], a[j].second);
            }
        }
    }

    cout << dp[k] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 1;
#endif
    while (t--) solve();
}