#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

const int M = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    T = 1;
    // cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<long long> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 0; i < n; ++i) {
            pow2[i + 1] = pow2[i] * 2 % M;
        }
        vector<long long> cnt(40);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            int c = 0;
            int p = a[i];
            while (p % 2 == 0) {
                ++c;
                p /= 2;
            }
            ++cnt[c];
        }
        long long cc = n - cnt[0];
        long long ans = (pow2[n] + M - 1) % M;
        for (int i = 1; i < 40; ++i) {
            if (cnt[i] > 0) {
                ans = (ans + M - pow2[cc - 1]) % M;
                cc -= cnt[i];
            }
        }
        ans = (ans % M + M) % M;
        cout << ans << '\n';
    }
    return 0;
}