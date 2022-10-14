#include <bits/stdc++.h>

#define double long double
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(all(A));
    int u = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (u < n && A[u] <= A[i]) {
            u++;
        }
        if (u == n) {
            ans++;
        } else {
            if (A[u] > A[i]+k) ans++;
        }
    }
    cout << ans << '\n';

}