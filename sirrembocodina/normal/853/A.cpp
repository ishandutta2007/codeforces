#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    set<int> s;
    for (int i = k; i < k + n; i++) {
        s.insert(i);
    }

    int ans = 0;
    vector<int> t(n);

    for (int i = 0; i < n; i++) {
        t[a[i].second] = *s.lower_bound(a[i].second);
        ans += (t[a[i].second] - a[i].second) * a[i].first;
        s.erase(t[a[i].second]);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << t[i] + 1 << " ";
    }
}