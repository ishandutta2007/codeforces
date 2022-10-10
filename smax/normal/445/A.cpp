#include <bits/stdc++.h>
using namespace std;

string grid[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> grid[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == '-')
                cout << '-';
            else if (i % 2 == j % 2)
                cout << 'B';
            else
                cout << 'W';
        }
        cout << "\n";
    }

    return 0;
}