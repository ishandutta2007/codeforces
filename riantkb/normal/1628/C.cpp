// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 998244353;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        int m = n;
        if (n % 4 == 2) {
            m = n + 2;
        }
        vector<vector<int>> a(m, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        int l = 0, k = m - 1;
        while (k > 0) {
            vector<int> v;
            int ti = l, tj = l;
            int dd[] = { 0, 1, 0, -1 };
            for (int d = 0; d < 4; ++d) {
                for (int x = 0; x < k; ++x) {
                    v.push_back(a[ti][tj]);
                    ti += dd[d];
                    tj += dd[d ^ 1];
                }
            }
            for (int i = 0; i < (int)v.size(); ++i) {
                if (i % 4 < 2) {
                    ans ^= v[i];
                }
            }
            l += 2;
            k -= 4;
        }
        cout << ans << '\n';
    }

    return 0;
}