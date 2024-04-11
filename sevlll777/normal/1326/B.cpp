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
    int n;
    cin >> n;
    vector<int> B(n);
    fro (int i = 0; i < n; i++) cin >> B[i];
    vector<int> A(n);
    A[0] = B[0];
    int m = max(0LL, A[0]);
    for (int i = 1; i < n ;i++) {
        A[i] = B[i] + m;
        m = max(m, A[i]);
    }
    for (auto p : A) cout << p << ' ';

}