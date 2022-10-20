#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    // n = 100000;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        // a[i] = i * 1234 % 98765 + 1;
        cin >> a[i];
    }
    int threshold = 400;
    int ans = 1;
    for (int d = -threshold; d <= threshold; ++d) {
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            v.push_back(a[i] - i * d);
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (i > 0 && v[i - 1] == v[i]) {
                ++cnt;
            }
            else {
                cnt = 1;
            }
            ans = max(ans, cnt);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((j - i) * threshold > 100010) break;

            if ((a[j] - a[i]) % (j - i) == 0 && abs((a[j] - a[i]) / (j - i)) > threshold) {
                int d = (a[j] - a[i]) / (j - i);
                int cnt = 1;
                for (int k = i - 1; k >= 0; --k) {
                    int x = a[i] + (k - i) * d;
                    if (!(0 <= x && x <= 100010)) break;
                    if (x == a[k]) ++cnt;
                }
                for (int k = i + 1; k < n; ++k) {
                    int x = a[i] + (k - i) * d;
                    if (!(0 <= x && x <= 100010)) break;
                    if (x == a[k]) ++cnt;
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << n - ans << '\n';
    return 0;
}