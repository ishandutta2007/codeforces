#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map <int, int> x;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (x.count(l)) {
            x[l] = min(x[l], r);
        } else {
            x[l] = r;
        }
    }

    int cur = 0;

    int ans = 0;

    multiset <int> dp;
    dp.insert(0);

    for (auto t : x) {
        int y = t.second;
        auto pos = dp.lower_bound(t.first);
        if (pos == dp.end()) {
            dp.insert(y);
        } else {
            if (*pos > y) {
                dp.erase(pos);
                dp.insert(y);
            }
        }
    }

    cout << dp.size() - 1 << "\n";
}