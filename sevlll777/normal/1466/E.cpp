#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> X(n);
        for (int i = 0; i < n; i++) cin >> X[i];
        int sum = 0;
        for (auto x : X) {
            sum += x % M;
            sum %= M;
        }
        vector<int> cnt(60);
        for (auto y : X) {
            for (int bit = 59; bit >= 0; bit--) {
                if ((y >> bit) & 1) {
                    cnt[bit]++;
                }
            }
        }
        for (int b = 0; b < 60; b++) {
            cnt[b] *= ((1LL << b) % M);
            cnt[b] %= M;
        }
        vector<int> heh(n);
        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit < 60; bit++) {
                if ((X[i] >> bit) & 1) {
                    heh[i] += cnt[bit];
                    heh[i] %= M;
                }
            }
        }
        int ans = 0;
        for (int bit = 59; bit >= 0; bit--) {
            int s = 0, kek = 0, sas = 0;
            for (int i = 0; i < n; i++) {
                if ((X[i] >> bit) & 1) {
                    s += (M - heh[i]);
                    s %= M;
                    sas += X[i];
                    sas %= M;
                    kek++;
                }
            }
            s += ((n * sas) % M);
            s %= M;
            s += ((kek * sum) % M);
            s %= M;
            s *= ((1LL << bit) % M);
            s %= M;
            s *= kek;
            s %= M;
            ans += s;
            ans %= M;
        }
        cout << ans << '\n';

    }
}