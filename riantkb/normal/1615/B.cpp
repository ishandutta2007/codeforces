// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 998244353;
const long long LM = 1LL << 60;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    vector<vector<int>> bc(200010, vector<int>(20));
    for (int i = 1; i < 200010; ++i) {
        bc[i] = bc[i - 1];
        for (int j = 0; j < 20; ++j) {
            if ((i >> j) & 1) {
                ++bc[i][j];
            }
        }
    }

    for (int _ = 0; _ < T; ++_) {
        int l, r;
        cin >> l >> r;
        int ma = 0;
        for (int i = 0; i < 20; ++i) {
            int c = bc[r][i] - bc[max(l - 1, 0)][i];
            ma = max(ma, c);
        }
        cout << r - l + 1 - ma << '\n';
    }

    return 0;
}