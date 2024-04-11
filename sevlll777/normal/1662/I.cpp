#include<bits/stdc++.h>
#define int long long
#define p pair<int, int>
#define endl '\n'
const int INF = 1000000001;

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<p> a(n);
    for (int q = 0; q < n; q++) {
        cin >> a[q].second;
        a[q].first = q*100;
    }
    vector<int> pref = {0};
    for (p q : a) {
        pref.push_back(pref.back()+q.second);
    }
    vector<int> s(m);
    for (int q = 0; q < m; q++) {
        cin >> s[q];
    }
    sort(s.begin(), s.end());
    int ans, now = 0;
    for (int q = 0; q < n; q++) {
        if (a[q].first < s[0]) {
            now += a[q].second;
        }
    }
    ans = now, now = 0;
    for (int q = n-1; q > -1; q--) {
        if (a[q].first > s.back()) {
            now += a[q].second;
        }
    }
    ans = max(ans, now);
    for (int q = 0; q < n; q++) {
        auto w1 = upper_bound(s.begin(), s.end(), a[q].first);
        if (w1 == s.begin() || w1 == s.end()) {
            continue;
        }
        int left = *(--w1), right = *(++w1);
        int me = min(right, 2*a[q].first-left);
        if (me == left) {
            continue;
        }
        int ind = lower_bound(a.begin(), a.end(), p((me+right+1)/2, -INF))-a.begin();
        ans = max(ans, pref[ind]-pref[q]);
    }
    cout << ans << endl;
    return 0;
}