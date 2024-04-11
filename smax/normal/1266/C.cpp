#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int r, c;
    cin >> r >> c;

    if (r == 1 && c == 1)
        cout << "0\n";
    else if (r == 1) {
        for (int j=0; j<c; j++)
            cout << j + 2 << " ";
        cout << "\n";
    } else if (c == 1) {
        for (int i=0; i<r; i++)
            cout << i + 2 << "\n";
    } else {
        for (int i=1; i<=r; i++) {
            for (int j=1; j<=c; j++)
                cout << (i + c) * j << " ";
            cout << "\n";
        }
    }

    return 0;
}