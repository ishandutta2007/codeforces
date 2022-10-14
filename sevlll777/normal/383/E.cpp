#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;
const int N = (1 << 24);
int F[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int _ = 0; _ < n; _++) {
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0; i < 3; i++) {
            mask |= (1 << (s[i] - 'a'));
        }
        F[mask]++;
    }
    for (int i = 0; i < 24; i++) {
        for (int mask = 0; mask < (1 << 24); mask++) {
            if ((mask >> i) & 1) {
                F[mask] += F[mask ^ (1 << i)];
            }
        }
    }
    long long ans = 0;
    for (int mask = 0; mask < (1 << 24); mask++) {
        long long val = n - F[mask];
        assert(val >= 0);
        ans ^= (val * val);
    }
    cout << ans << '\n';
}