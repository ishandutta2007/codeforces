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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cnt[a[i]];
        }
        int mi = M;
        int x = 0, y = M;
        for (int i = 0, j = 0, c = -n; i < n + 1; ++i) {
            while (j < n + 1 && c < k) {
                c += cnt[j] * 2;
                ++j;
            }
            if (c >= k && mi > j - i) {
                mi = j - i;
                x = i;
                y = j;
            }
            c -= cnt[i] * 2;
        }
        int d = 0;
        vector<int> idx(n + 1, -1);
        idx[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (x <= a[i] && a[i] < y) {
                ++d;
            }
            else {
                --d;
            }
            if (d > 0 && idx[d] == -1) {
                idx[d] = i + 1;
            }
        }
        idx[k] = n;
        cout << x << ' ' << y - 1 << '\n';
        for (int i = 0; i < k; ++i) {
            cout << idx[i] + 1 << ' ' << idx[i + 1] << '\n';
        }
    }
    return 0;
}