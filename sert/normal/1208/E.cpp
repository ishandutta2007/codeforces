#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 41;
// const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
    int nn, w;
    cin >> nn >> w;
    vector<ll> sum(w, 0);
    ll tot = 0;
    for (int i = 0; i < nn; i++) {
        int m;
        cin >> m;
        vector<ll> cur(m);
        for (int j = 0; j < m; j++) cin >> cur[j];
        auto it = max_element(cur.begin(), cur.end());
        int val = *it;

        if (val < 0 && m * 2 <= w) continue;
        int zp = w - m;

        tot += val;

        set<pair<ll, int>> s;        
        for (int j = 0; j < m; j++) {
            s.insert(make_pair(cur[j], j));
            while (j - s.rbegin()->second + m > w) {
                s.erase(make_pair(s.rbegin()->first, s.rbegin()->second));
            }
            if (j >= zp)
                sum[j] += s.rbegin()->first - val;
            else
                sum[j] += max(0ll, s.rbegin()->first) - val;
        }

        int big = w;
        s.clear();
        for (int j = m - 1; j >= 0; j--) {
            big--;
            if (big < m) break;
            s.insert(make_pair(cur[j], j));
            while (big - s.rbegin()->second < 0) {
                s.erase(make_pair(s.rbegin()->first, s.rbegin()->second));
            }
            if (big + zp < w)
                sum[big] += s.rbegin()->first - val;
            else
                sum[big] += max(0ll, s.rbegin()->first) - val;
        }
    }

    for (int i = 0; i < w; i++) cout << sum[i] + tot << " ";
    cout << "\n";
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tst = 1;
    //scanf("%d", &tst);
    // cin >> tst;
#ifdef MADE_BY_SERT
    D = true;  
    tst = 3;  
    while (tst--) {
        solve();
    }
#else
    while (tst--) solve();
#endif
}