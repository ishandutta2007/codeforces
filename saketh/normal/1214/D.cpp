#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int N, M;
vector<string> grid;

bool find() {
    vector<vector<int>> path(N, vector<int>(M, -1));
    path[0][0] = -2;
    F0R (i, N) F0R (j, M) if ((i || j) && grid[i][j] == '.') {
        if (i > 0 && path[i-1][j] != -1) path[i][j] = 0;
        else if (j > 0 && path[i][j-1] != -1) path[i][j] = 1;
    }
    if (path[N-1][M-1] == -1) return false;

    for (int i = N-1, j = M-1; path[i][j] != -2; ) {
        if (i<N-1 || j<M-1) grid[i][j] = '#';
        if (path[i][j]) j--;
        else i--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    grid.resize(N);
    F0R (i, N) cin >> grid[i];

    int ans = 0;
    while (find()) ans++;
    cout << ans << endl;

    return 0;
}