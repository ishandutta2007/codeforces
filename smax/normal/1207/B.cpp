#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a[50][50], b[50][50] = {0};
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    vector<pair<int, int>> operations;
    for (int i=0; i<n-1; i++)
        for (int j=0; j<m-1; j++)
            if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
                b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
                operations.push_back(make_pair(i, j));
            }

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (a[i][j] != b[i][j]) {
                cout << "-1\n";
                return 0;
            }
    cout << operations.size() << "\n";
    for (pair<int, int> p : operations)
        cout << p.first + 1 << " " << p.second + 1 << "\n";

    return 0;
}