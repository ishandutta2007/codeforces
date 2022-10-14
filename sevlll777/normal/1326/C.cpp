#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fro for
#define pb push_back
#define ld long double
const int M = 998244353;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> P(n);
    vector<int> A(n+1);
    fro (int i = 0; i < n; i++) {
        cin >> P[i];
        A[P[i]] = i;
    }
    int ans = 1;
    int aans = 0;
    vector<int> lol;
    for (int i = n; i >= n - k + 1; i--) {
        lol.pb(A[i]);
    }
    aans = (n * (n + 1) - (n - k) * (n - k + 1)) / 2;
    sort(lol.begin(), lol.end());
    for (int y = 0; y < (int) lol.size() - 1; y++) {
        ans *= abs(lol[y + 1] - lol[y]);
        ans %= M;
    }
    cout << aans << ' ' << ans;



}