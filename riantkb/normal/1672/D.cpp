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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            --b[i];
        }
        vector<int> cnt(n);
        bool ok = true;
        for (int i = 0, j = 0; i < n; ++i) {
            if (i > 0 && b[i - 1] == b[i] && cnt[b[i]] > 0) {
                --cnt[b[i]];
            }
            else {
                while (j < n && b[i] != a[j]) {
                    ++cnt[a[j]];
                    ++j;
                }
                if (j == n) {
                    ok = false;
                    break;
                }
                ++j;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';

    }

    return 0;
}