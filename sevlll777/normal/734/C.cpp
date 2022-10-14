#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fro for
#define pb push_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k, x, s;
    cin >> n >> m >> k >> x >> s;
    vector<int> A(m), B(m), C(k), D(k);
    for (int i = 0; i < m; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];
    for (int i = 0; i < k; i++) cin >> C[i];
    for (int i = 0; i < k; i++) cin >> D[i];
    int ans = n * x;
    for (int i = 0; i < m; i++) {
        if (s >= B[i]) {
            int s2 = s - B[i];
            int ind = (int) (upper_bound(D.begin(), D.end(), s2) - D.begin()) - 1;
            if (0 <= ind && ind < D.size()) {
                ans = min(ans, (n - C[ind]) * A[i]);
            }
            ans = min(ans, A[i] * n);
        }
    }
    for (int i = 0; i < k; i++) {
        if (s >= D[i]) {
            ans = min(ans, (n - C[i]) * x);
        }
    }
    cout << max(0LL, ans);
}