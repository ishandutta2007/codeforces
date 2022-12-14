// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = 505, mod = 0, C = N * N;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, k, cc, comp[N][N], mark[N][N], sz[C], cnt[C], cursz = 0, sum[N][N];
string s[N];
bool check(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < n && s[i][j] != 'X'); }

void dfs(int i, int j, int cp) {
    if (mark[i][j]++)
        return;
    comp[i][j] = cp;
    for (int d = 0; d < 4; ++d) {
        int x = i + dx[d], y = j + dy[d];
        if (check(x, y))
            dfs(x, y, cp);
    }
}

void add(int x, int y, int p) {
   // cout << " see " << x << ' ' << y << endl;
    if (!check(x, y))
        return;
   // cout << x << ' ' << y << ' ' << p << ' ' << comp[x][y] << ' ' << sz[comp[x][y]] << endl;
    if (cnt[comp[x][y]] != 0)
        cursz -= sz[comp[x][y]];
    cnt[comp[x][y]] += p;
    if (cnt[comp[x][y]] != 0)
        cursz += sz[comp[x][y]];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (check(i, j) && !mark[i][j])
                dfs(i, j, cc++);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            sum[i][j] = (s[i - 1][j - 1] == '.') + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) if (check(i, j))
            sz[comp[i][j]]++;
    int best = k * k;
    for (int strow = 0; strow < n - k + 1; ++strow) {
        memset(cnt, 0, sizeof cnt);
        cursz = 0;
        for (int j = 0; j < n; ++j) {
   //         cout << " hi " << strow << ' ' << j << endl;
            for (int i = strow; i < strow + k; ++i)
                add(i, j, 1);
            if (j >= k)
                for (int i = strow; i < strow + k; ++i)
                    add(i, j - k, -1);
            if (j >= k - 1) {
                int i = strow;
                int s = j - k + 1;
                int x = sum[i + k][s + k] - sum[i][s + k] - sum[i + k][s] + sum[i][s];
                for (int p = s; p < s + k; ++p)
                    add(i - 1, p, 1), add(i + k, p, 1);
                for (int p = i; p < i + k; ++p)
                    add(p, s - 1, 1), add(p, s + k, 1);
                best = max(best, cursz - x + k * k);
 //               cout << i << ' ' << j << ' ' << x << ' ' << cursz << ' ' << k * k << endl;
                for (int p = s; p < s + k; ++p)
                    add(i - 1, p, -1), add(i + k, p, -1);
                for (int p = i; p < i + k; ++p)
                    add(p, s - 1, -1), add(p, s + k, -1);
//                return 0;
            }
        }
    }
    cout << best << endl;
}