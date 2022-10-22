#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
    if (x < y) {
        return gcd(y, x);
    }
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

const int INF = (int)1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int minl = INF;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][i];
        if (a[i][i] == 1) {
            minl = 1;
        }
    }
    int ans;
    if (minl == 1) {
        ans = n;
        for (int i = 0; i < n; ++i) {
            if (a[i][i] == 1) {
                --ans;
            }
        }
        cout << ans << '\n';
        return 0;
    }
    for (int len = 1; len < n; ++len) {
        for (int i = 0; i + len < n; ++i) {
            a[i][i + len] = gcd(a[i][i + len - 1], a[i + len][i + len]);
            if (a[i][i + len] == 1) {
                minl = min(minl, len + 1);
            }
        }
    }
    if (minl == INF) {
        cout << "-1\n";
        return 0;
    }
    //cout << minl << '\n';
    cout << minl - 1 + n - 1 << '\n';

    return 0;
}