#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> m(r, vector<int>(c, 1));
    if (r == 1 && c == 1) {
        cout << "0\n";
        return 0;
    }
    if (r == 1 || c == 1) {
        int cur = 2;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << cur << " ";
                ++cur;
            }
            cout << '\n';
        }
        return 0;
    }
    int cur = 1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            m[i][j] *= cur;
        }
        ++cur;
    }
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < r; ++i) {
            m[i][j] *= cur;
        }
        ++cur;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << m[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}