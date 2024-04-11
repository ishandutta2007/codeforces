#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<string, int>> t;
    vector<int> q(n);
    vector<int> mx(n + 1, -1);
    int cur = 0;
    int cnt = 0;
    forn (i, 2 * n) {
        string s;
        cin >> s;
        if (s == "+") {
            cur++;
            cnt++;
            t.push_back({s, 0});
        } else {
            cnt--;
            int x;
            cin >> x;
            x--;
            q[x] = cur;
            if (mx[cur] > x || cnt < 0) {
                cout << "NO" << endl;
                return 0;
            }
            t.push_back({s, x});
            mx[cur] = x;
        }
    }
    set<int> ind;
    forn (i, n) {
        ind.insert(i);
    }
    vector<int> ans(n);
    forn (i, n) {
        auto it = ind.lower_bound(q[i]);
        it--;
        ans[*it] = i;
        ind.erase(it);
    }
    cur = 0;
    forn (i, 2 * n) {
        if (t[i].first == "+") {
            ind.insert(ans[cur]);
            cur++;
        } else {
            if (*ind.begin() != t[i].second) {
                cout << "NO" << endl;
                return 0;
            }
            ind.erase(ind.begin());
        }
    }
    cout << "YES" << endl;
    forn (i, n) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}