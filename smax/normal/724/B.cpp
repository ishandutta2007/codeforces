#include <bits/stdc++.h>
using namespace std;

int n, m, a[20][20];

bool can(int c1, int c2) {
    bool ret = true;
    for (int i=0; i<n; i++) {
        int cnt = 0;
        swap(a[i][c1], a[i][c2]);
        for (int j=0; j<m; j++)
            if (a[i][j] != j + 1)
                cnt++;
        if (cnt > 2)
            ret = false;
        swap(a[i][c1], a[i][c2]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    for (int i=0; i<m; i++)
        for (int j=i; j<m; j++)
            if (can(i, j)) {
                cout << "YES\n";
                return 0;
            }

    cout << "NO\n";

    return 0;
}