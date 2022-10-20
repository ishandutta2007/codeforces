#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    // T = 1;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && a[i] == a[i - 1]) continue;
            int c = 1;
            int last = i;
            while (true) {
                auto itr = lower_bound(a.begin() + last + 1, a.end(), a[last] * 2 - a[i]);
                if (itr == a.end()) break;
                ++c;
                last = itr - a.begin();
            }
            ans = max(ans, c);
        }
        cout << n - ans << '\n';
    }
    return 0;
}