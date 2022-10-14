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
    vector<int> P(n), ind(n+1);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
        ind[P[i]] = i;
    }
    int cnt = 1;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (ind[i] > ind[i - 1]) {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout << n - ans;

}