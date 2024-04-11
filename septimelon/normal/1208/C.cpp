#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i += 4) {
        for (int j = 0; j < n; j += 4) {
            for (int q = 0; q < 4; q++) {
                for (int w = 0; w < 4; w++) {
                    a[i+q][j+w] = i * n + j * 4 + q * 4 + w;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}