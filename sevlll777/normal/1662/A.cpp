#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl '\n'
#define int long long
typedef long double ld;

bool comp(vector<int> &a, vector<int> &b) {
    return a.size() < b.size();
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> kekw(n);
    vector<int> diff(11);
    for (int i = 0; i < n; i++) {
        cin >> kekw[i].first >> kekw[i].second;
        swap(kekw[i].first, kekw[i].second);
        diff[kekw[i].first] = max(diff[kekw[i].first], kekw[i].second);
    }
    int sus = 0;
    for (int i = 1; i < 11; i++) {
        if (!diff[i]) {
            cout << "MOREPROBLEMS" << endl;
            return;
        }
        sus+=diff[i];
    }
    cout << sus << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}