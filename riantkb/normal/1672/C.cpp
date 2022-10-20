// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        int c = 0;
        int l = M, r = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i > 0 && a[i - 1] == a[i]) {
                ++c;
                l = min(l, i - 1);
                r = max(r, i);
            }
        }
        if (c <= 1) {
            cout << 0 << '\n';
        }
        else {
            cout << max(1, r - l + 1 - 3) << '\n';
        }
    }

    return 0;
}