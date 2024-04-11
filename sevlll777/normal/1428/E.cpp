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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    vector<int> B(n, 1);
    k -= n;
    set<pair<int, int>> O;
    for (int i = 0; i < n; i++) {
        if (B[i] != A[i]) {
            int r = A[i] % B[i];
            int f1 = r * r + (A[i] * A[i] - r * r) / B[i];
            int r2 = A[i] % (B[i] + 1);
            int f2 = r2 * r2 + (A[i] * A[i] - r2 * r2) / (B[i] + 1);
            O.insert({f2 - f1, i});
        }
    }
    for (int _ = 0; _ < k; _++) {
        pair<int, int> heh = *O.begin();
        O.erase(heh);
        int i = heh.second;
        B[i]++;
        if (B[i] != A[i]) {
            int r = A[i] % B[i];
            int f1 = r + (A[i] * A[i] - r * r) / B[i];
            int r2 = A[i] % (B[i] + 1);
            int f2 = r2 + (A[i] * A[i] - r2 * r2) / (B[i] + 1);
            O.insert({f2 - f1, i});
        }
    }
    int S = 0;
    for (int i = 0; i < n; i++) {
        int r = A[i] % B[i];
        int f1 = r + (A[i] * A[i] - r * r) / B[i];
        S += f1;
    }
    cout << S << '\n';
}