#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    int maxd = 1;
    int cdel = 1;
    for (int i = 1; n - i >= p; ++i) {
        --cdel;
        cdel += a[i - 1] - a[i];
        cdel = min(cdel, n - i);
        maxd = max(maxd, cdel);
    }
    
    int minx = a[0] - n + 1;
    int wmaxd0 = minx;
    cdel = 0;
    for (int i = 1; i < n; ++i) {
        --cdel;
        cdel += a[i - 1] - a[i];
        if (cdel < 0) {
            ++cdel;
            ++minx;
        }
    }
    
    vector<int> ans;
    for (int x = minx; x < a[0] + n; ++x) {
        if (x - wmaxd0 + maxd >= p) {
            break;
        }
        ans.push_back(x);
    }
    
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
       solve();
    }
   
    return 0;
}