#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 101;
vector<pair<int, int>> g[N];
int dp[N][N][26];

int dfs(int x, int y, int c) {
    if (dp[x][y][c])
        return dp[x][y][c];
    dp[x][y][c] = 2;
    for (auto &p : g[x]) {
        if (p.second >= c && dfs(y, p.first, p.second) == 2)
            dp[x][y][c] = 1;
    }
    return dp[x][y][c];
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b;
    char c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c - 'a'});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dfs(i, j, 0) == 1)
                cout << 'A';
            else
                cout << 'B';
        }
        cout << '\n';
    }

}