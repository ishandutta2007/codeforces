#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (min(a, b) > 1) {
        cout << "NO\n";
        return 0;
    }
    int cou = max(a, b);
    if (cou == 1 && (n == 3 || n == 2)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (cou == 1 && n > 3) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (abs(i - j) == 1) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << '\n';
        }
        return 0;
    }
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && i % cou == j % cou) {
                m[i][j] = 1;
            }
        }
    }
    if (b > 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    m[i][j] = 1 - m[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << m[i][j];
        }
        cout << '\n';
    }
    return 0;
}