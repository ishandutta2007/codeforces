#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int g = 0;
    for (int i = 1; i < n; i++) g = gcd(g, A[i] - A[i - 1]);
    while (m--) {
        int r;
        cin >> r;
        cout << gcd(g, A[0]+r) << ' ';
    }
    cout << '\n';
}