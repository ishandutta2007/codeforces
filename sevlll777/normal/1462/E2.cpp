#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
int fact[200009], inv_fact[200009];

int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x % 2) {
            ans *= a;
            ans %= M;
        }
        a *= a;
        a %= M;
        x /= 2;
    }
    return ans;
}

int C(int k, int n) {
    if (k < 0 || k > n) return 0;
    int f = (inv_fact[k] * inv_fact[n - k]) % M;
    f *= fact[n];
    f %= M;
    return f;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fact[0] = inv_fact[0] = 1;
    for (int x = 1; x <= 200007; x++) {
        fact[x] = (fact[x - 1] * x) % M;
        inv_fact[x] = binpow(fact[x], M - 2);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        int r = 0;
        int ans = 0;
        for (int l = 0; l < n; l++) {
            while (r < A.size() && A[r] <= k + A[l]) {
                r++;
            }
            int num = r-l-1;
            ans += C(m-1,num);
            ans %= M;
        }
        cout << ans << '\n';
    }
}