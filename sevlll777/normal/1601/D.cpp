#include <bits/stdc++.h>

#define int long long
#define pb push_back
//#define endl '\n'
#define all(x) x.begin(), x.end()
const int INF = 1000000001;

using namespace std;

bool cmp(pair<int, int> p, pair<int, int> p2) {
    if (max(p.first, p.second) < max(p2.first, p2.second)) {
        return true;
    }
    if (max(p.first, p.second) > max(p2.first, p2.second)) {
        return false;
    }
    if (min(p.first, p.second) >= min(p2.first, p2.second)) {
        return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> x;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x.pb({a, b});
    }
    sort(all(x), cmp);
    int ans = 0;
    for (auto p : x) {
        if (p.first >= d) {
            ans++;
            d = max(d, p.second);
        }
    }
    cout << ans << '\n';
}