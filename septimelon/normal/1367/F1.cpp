#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get_ind(int x, const vector<int>& sa) {
    int l = 0;
    int r = sa.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (sa[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> sa = a;
    sort(sa.begin(), sa.end());
    vector<int> aind(n);
    for (int i = 0; i < n; ++i) {
        aind[get_ind(a[i], sa)] = i;
    }
    
    int ans = 0;
    int curl = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (aind[i + 1] > aind[i]) {
            ++curl;
        } else {
            ans = max(ans, curl);
            curl = 1;
        }
    }
    ans = max(ans, curl);
    
    cout << n - ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}