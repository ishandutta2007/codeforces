#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> ansx;
    vector<int> ansy;
    int a[50][50], b[50][50];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == 1 && a[i-1][j] == 1 && a[i][j-1] == 1 && a[i-1][j-1] == 1) {
                b[i][j] = 1;
                b[i-1][j] = 1;
                b[i][j-1] = 1;
                b[i-1][j-1] = 1;
                ansx.push_back(i);
                ansy.push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << ansx.size() << endl;
    for (int i = 0; i < ansx.size(); i++) {
        cout << ansx[i] << " " << ansy[i] << endl;
    }
    return 0;
}