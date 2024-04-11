#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int64_t ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            if (s[j - 1] == 'S') {
                a[i][j] = 1;
            }
            if (s[j - 1] == 'W') {
                a[i][j] = -1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 1) {
                if (a[i - 1][j] == -1 || a[i + 1][j] == -1 || a[i][j + 1] == -1 || a[i][j - 1] == -1) {
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 0) {
                cout << "D";
            }
            if (a[i][j] == -1) {
                cout << "W";
            }
            if (a[i][j] == 1) {
                cout << "S";
            }
        }
        cout << endl;
    }
    return 0;
}