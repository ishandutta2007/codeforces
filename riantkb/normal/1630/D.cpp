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
    // T = 1;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int g = 0;
        for (int i = 0; i < m; ++i) {
            int b;
            cin >> b;
            g = gcd(g, b);
        }
        vector<int> cnt(g);
        vector<long long> mi(g, M);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            mi[i % g] = min(mi[i % g], abs(a[i]));
            if (a[i] < 0) {
                cnt[i % g] ^= 1;
            }
            sum += abs(a[i]);
        }
        long long ans1 = sum;
        long long ans2 = sum;

        for (int i = 0; i < g; ++i) {
            if (cnt[i]) {
                ans1 -= mi[i] * 2;
            }
            else {
                ans2 -= mi[i] * 2;
            }
        }
        cout << max(ans1, ans2) << '\n';
    }
    return 0;
}