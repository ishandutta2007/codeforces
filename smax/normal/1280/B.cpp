#include <bits/stdc++.h>
using namespace std;

string grid[60];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;

        bool aExists = false, aOnEdge = false, aFullEdge = false, aAcross = false, aCorner = false, aFull = true;
        for (int i=0; i<r; i++) {
            cin >> grid[i];
            bool across = true;
            for (int j=0; j<c; j++) {
                if (grid[i][j] == 'A') {
                    aExists = true;
                    if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
                        aOnEdge = true;
                    if (i == 0 && (j == 0 || j == c - 1) || i == r - 1 && (j == 0 || j == c - 1))
                        aCorner = true;
                } else {
                    across = false;
                    aFull = false;
                }
            }
            if (across) {
                aAcross = true;
                if (i == 0 || i == r - 1)
                    aFullEdge = true;
            }
        }

        if (!aExists)
            cout << "MORTAL\n";
        else if (aFull)
            cout << "0\n";
        else if (aFullEdge)
            cout << "1\n";
        else {
            for (int j=0; j<c; j++) {
                bool across = true;
                for (int i=0; i<r; i++)
                    if (grid[i][j] == 'P') {
                        across = false;
                        break;
                    }
                if (across) {
                    if (j == 0 || j == c - 1) {
                        aFullEdge = true;
                        break;
                    }
                    aAcross = true;
                }
            }
            if (aFullEdge)
                cout << "1\n";
            else if (aAcross || aCorner)
                cout << "2\n";
            else if (aOnEdge)
                cout << "3\n";
            else
                cout << "4\n";
        }
    }

    return 0;
}