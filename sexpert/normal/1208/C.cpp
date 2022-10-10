#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int grid[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n / 4; i++) {
        for(int j = 0; j < n / 4; j++) {
            int st = (n / 4) * i + j;
            for(int r = 0; r < 4; r++) {
                for(int c = 0; c < 4; c++) {
                    grid[4*i + r][4*j + c] = 16*st + 4*r + c;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << '\n';
    }
}