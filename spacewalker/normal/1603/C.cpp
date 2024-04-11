#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

ll ceil(ll a, ll b) {
    return a / b + (a % b ? 1 : 0);
}

ll solve() {
    int n; scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
unordered_map<int, int> frontElems{{arr[n-1], 1}}, nfes;
    ll ans = 0;
    for (int i = n - 2; i >= 0; --i) {
//        printf("elem %lld\n", arr[i]);
        nfes.clear();
        for (auto [fe, c] : frontElems) {
            ll sp = ceil(arr[i], fe);
//            printf("fe [%d %d] need %lld\n", fe, c, sp);
            ans = (ans + (sp - 1) * c * (i + 1)) % MOD;
            nfes[arr[i] / sp] += c;
        }
        nfes[arr[i]]++;
        swap(frontElems, nfes);
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%lld\n", solve());
    }
}