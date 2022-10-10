#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, qs;

int ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
    cout.flush();
    assert(qs++ <= n*n);
    int r;
    cin >> r;
    if(r == -1)
        exit(0);
    return r;
}

int grid[51][51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    grid[1][1] = 1;
    grid[n][n] = 0;

    for(int i = 3; i <= n; i += 2) {
        int r = ask(i - 2, 1, i, 1);
        if(r == 1)
            grid[i][1] = grid[i - 2][1];
        else
            grid[i][1] = 1 - grid[i - 2][1];
    }
    int r = ask(n - 1, 1, n, 2);
    if(r == 1)
        grid[n][2] = grid[n - 1][1];
    else
        grid[n][2] = 1 - grid[n - 1][1];
    for(int i = n - 3; i > 0; i -= 2) {
        int r = ask(i, 1, i + 2, 1);
        if(r == 1)
            grid[i][1] = grid[i + 2][1];
        else
            grid[i][1] = 1 - grid[i + 2][1];
    }
    for(int i = n - 2; i > 0; i -= 2) {
        int r = ask(i, 2, i + 2, 2);
        if(r == 1)
            grid[i][2] = grid[i + 2][2];
        else
            grid[i][2] = 1 - grid[i + 2][2];
    }
    for(int i = 1; i <= n - 2; i += 2) {
        int r = ask(i, 1, i + 1, 2);
        if(r == 1)
            grid[i + 1][2] = grid[i][1];
        else
            grid[i + 1][2] = 1 - grid[i][1];
    }

    for(int j = 3; j <= n; j++) {
        for(int i = 1; i <= n; i++) {
            if(i + j == 2*n)
                break;
            int r = ask(i, j - 2, i, j);
            if(r == 1)
                grid[i][j] = grid[i][j - 2];
            else
                grid[i][j] = 1 - grid[i][j - 2];
        }
    }

    bool flip = false;

    for(int i = 1; i <= n - 2; i++) {
        if(grid[i][i] == grid[i + 1][i + 1] && grid[i][i] != grid[i + 2][i + 2]) {
            if(grid[i][i + 1] == grid[i + 2][i + 1]) {
                int r = ask(i, i, i + 2, i + 1);
                if(r == 1)
                    flip = (grid[i][i] != grid[i + 2][i + 1]);
                else
                    flip = (grid[i][i] == grid[i + 2][i + 1]);
            }
            else {
                int r = ask(i, i + 1, i + 2, i + 2);
                if(r == 1)
                    flip = (grid[i][i + 1] != grid[i + 2][i + 2]);
                else
                    flip = (grid[i][i + 1] == grid[i + 2][i + 2]);
            }
            break;
        }
        if(grid[i][i] != grid[i + 1][i + 1] && grid[i + 1][i + 1] == grid[i + 2][i + 2]) {
            if(grid[i][i + 1] == grid[i + 2][i + 1]) {
                int r = ask(i, i + 1, i + 2, i + 2);
                if(r == 1)
                    flip = (grid[i][i + 1] != grid[i + 2][i + 2]);
                else
                    flip = (grid[i][i + 1] == grid[i + 2][i + 2]);
            }
            else {
                int r = ask(i, i, i + 2, i + 1);
                if(r == 1)
                    flip = (grid[i][i] != grid[i + 2][i + 1]);
                else
                    flip = (grid[i][i] == grid[i + 2][i + 1]);
            }
            break;
        }
    }

    if(flip) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if((i + j) % 2)
                    grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    cout << "!\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}