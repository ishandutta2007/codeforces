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
        vector<int> cnt(n + 1);
        vector<vector<int>> v(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            v[cnt[a[i]]].push_back(i);
            ++cnt[a[i]];
        }
        vector<int> b(n);
        for (int i = 0; i < n + 1; ++i) {
            int c = v[i].size();
            sort(v[i].begin(), v[i].end(), [&](int x, int y) {
               return a[x] < a[y];
            });
            for (int j = 0; j < c; ++j) {
                b[v[i][j]] = a[v[i][(j + 1) % c]];
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << b[i] << (i < n - 1 ? ' ' : '\n');
        }
    }
    return 0;
}