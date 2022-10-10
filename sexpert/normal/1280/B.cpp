#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char grid[100][100];

void solve() {
    int r, c, cnt = 0;
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            cin >> grid[i][j];
            cnt += (grid[i][j] == 'A');
        }

    if(cnt == 0) {
        cout << "MORTAL\n";
        return;
    }
    if(cnt == r*c) {
        cout << "0\n";
        return;
    }
    for(int i = 0; i < r; i++) {
        if(grid[i][0] == 'P')
            break;
        if(i == r - 1) {
            cout << "1\n";
            return;
        }
    }

    for(int i = 0; i < r; i++) {
        if(grid[i][c - 1] == 'P')
            break;
        if(i == r - 1) {
            cout << "1\n";
            return;
        }
    }

    for(int j = 0; j < c; j++) {
        if(grid[0][j] == 'P')
            break;
        if(j == c - 1) {
            cout << "1\n";
            return;
        }
    }

    for(int j = 0; j < c; j++) {
        if(grid[r - 1][j] == 'P')
            break;
        if(j == c - 1) {
            cout << "1\n";
            return;
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == 'P')
                break;
            if(j == c - 1) { 
                cout << "2\n";
                return;
            }
        }
    }
    for(int j = 0; j < c; j++) {
        for(int i = 0; i < r; i++) {
            if(grid[i][j] == 'P')
                break;
            if(i == r - 1) {
                cout << "2\n";
                return;
            }
        }
    }

    cnt = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                cnt += (grid[i][j] == 'A');
            }
        }
    }

    if(cnt == 0) {
        cout << "4\n";
        return;
    }

    if(grid[0][0] == 'A' || grid[r - 1][0] == 'A' || grid[0][c - 1] == 'A' || grid[r - 1][c - 1] == 'A') {
        cout << "2\n";
        return;
    }
    cout << "3\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();   
}