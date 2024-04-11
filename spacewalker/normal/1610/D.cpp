#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MOD = 1000000007;

ll modexp(ll b, ll e) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    vector<int> v2(32);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        int p = 0;
        while (x % 2 == 0) {
            p++; x /= 2;
        }
        ++v2[p];
    }
    int ans = 0;
    for (int k = 0; k < 32; ++k) {
        if (v2[k] == 0) continue;
        int totalOther = 0;
        for (int j = k + 1; j < 32; ++j) totalOther += v2[j];
        ll pickHere = modexp(2, v2[k] - (k == 0 ? 0 : 1)) + MOD - 1;
        ll pickOther = modexp(2, totalOther);
        ans = (ans + pickHere * pickOther % MOD) % MOD;
    }
    printf("%d\n", ans);
}