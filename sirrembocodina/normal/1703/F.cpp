#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (a[i] < i + 1) {
                b.push_back(a[i]);
            }
        }
        sort(b.begin(), b.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= i + 1) {
                continue;
            }
            ans += b.end() - upper_bound(b.begin(), b.end(), i + 1);
        }
        cout << ans << '\n';
    }
}