#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
int n;

int solve(vector<int> X, int bit) {
    if (bit < 0) return 0;
    vector<int> Y, Z;
    for (auto x : X) {
        if ((x >> bit) & 1) {
            Y.pb(x);
        } else {
            Z.pb(x);
        }
    }
    if (Y.empty() || Z.empty()) return solve(X, bit-1);
    int y1 = solve(Y, bit - 1), z1 = solve(Z, bit - 1);
    return (int) (min(y1 + Z.size() - 1, z1 + Y.size() - 1));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << solve(A, 31) << '\n';
}