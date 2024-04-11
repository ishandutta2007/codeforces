#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    vector<pair<int, int>> b;
    b.push_back({1, a[0]});
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            ++b.back().first;
        } else {
            b.push_back({1, a[i]});
        }
    }
    sort(b.begin(), b.end());
    
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int ca = 0;
        for (int i = 0; i < b.size(); ++i) {
            ca += b[i].first / mid;
        }
        if (ca >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    vector<int> ans;
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < b[i].first / l; ++j) {
            ans.push_back(b[i].second);
        }
    }
    
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}