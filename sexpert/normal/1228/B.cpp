#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    bool bad = false;
    vector<vector<int>> grid(r, vector<int>(c, -1));

    for(int i = 0; i < r; i++) {
        int x;
        cin >> x;
        for(int y = 0; y < x; y++)
            grid[i][y] = 1;
        if(x < c)
            grid[i][x] = 0;
    }
    for(int i = 0; i < c; i++) {
        int x;
        cin >> x;
        for(int y = 0; y < x; y++) {
            if(grid[y][i] == 0)
                bad = true;
            grid[y][i] = 1;
        }
        if(x < r) {
            if(grid[x][i] == 1)
                bad = true;
            grid[x][i] = 0;
        }
    }
    if(bad) {
        cout << "0\n";
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(grid[i][j] == -1)
                cnt++;

    cout << mpow(2, cnt) << '\n';
}