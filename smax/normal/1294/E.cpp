#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }

    int ret = 0;
    for (int j=0; j<m; j++) {
        vector<int> cnt(n);
        for (int i=0; i<n; i++)
            if (a[i][j] % m == j && a[i][j] / m < n)
                cnt[(i - a[i][j] / m + n) % n]++;

        int mn = INT_MAX;
        for (int i=0; i<n; i++)
            mn = min(mn, n - cnt[i] + i);
        ret += mn;
    }

    cout << ret << "\n";

    return 0;
}