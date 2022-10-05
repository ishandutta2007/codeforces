#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "stack"

#define all(x) (x).begin(), (x).end()

using namespace std;
vector<string> pole;
vector<vector<int>> ans;
vector<vector<int>> t;
int tt = 0;
vector<vector<char>> sn;
pair<int, int> mv(int x, int y) {
    if (pole[x][y] == 'R') {
        y++;
    } else if (pole[x][y] == 'L') {
        y--;
    } else if (pole[x][y] == 'U') {
        x--;
    } else {
        x++;
    }
    return {x, y};
}
void ansdfs(int is, int js) {
    stack<pair<int, int>> crd;
    crd.push({is, js});
    int x = 0;
    while (!crd.empty()) {
        auto [i, j] = crd.top();
        if (i >= 20000) {
            i -= 20000;
            ans[i][j] = x;
            if (sn[i][j] != 2) {
                sn[i][j] = 2;
                x = ans[i][j];
                crd.pop();
                continue;
            }
            sn[i][j] = 2;
            x = 0;
            crd.pop();
            continue;
        }
        if (i < 0 or i == ans.size() or j < 0 or j == ans[0].size()) {
            x = 0;
            crd.pop();
            continue;
        }
        if (sn[i][j] == 1) {
            sn[i][j] = 2;
            x = ans[i][j] = tt - t[i][j];
            crd.pop();
            continue;
        }
        if (sn[i][j] == 2) {
            x = 0;
            crd.pop();
            continue;
        }
        t[i][j] = tt++;
        sn[i][j] = 1;
        crd.top().first += 20000;
        auto[ii, jj] = mv(i, j);
        crd.push({ii, jj});
    }
}
int an2(int is, int js) {
    stack<pair<int, int>> crd;
    crd.push({is, js});
    int x = 0;
    while (!crd.empty()) {
        auto [i, j] = crd.top();
        if (i < 0 or i == ans.size() or j < 0 or j == ans[0].size()) {
            x = 0;
            crd.pop();
            continue;
        }
        if (ans[i][j] > 0) {
            x = ans[i][j];
            crd.pop();
            continue;
        }
        if (ans[i][j] == -1) {
            ans[i][j] = ++x;
            crd.pop();
            continue;
        }
        auto[ii, jj] = mv(i, j);
        crd.push({ii, jj});
        ans[i][j] = -1;
    }
    return ans[is][js];
}
void solve(){
    int n, m;
    cin >> n >> m;
    pole.assign(n, {});
    t.assign(n, vector<int>(m));
    sn.assign(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        cin >> pole[i];
    }
    ans.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ansdfs(i, j);
        }
    }
    int an = 0, x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            an2(i, j);
            if (ans[i][j] > an) {
                an = ans[i][j];
                x = i + 1;
                y = j + 1;
            }
        }
    }
    cout << x << ' ' << y << ' ' << an << '\n';
    for (auto &i : ans)
        i.clear();
    for (auto &i : pole)
        i.clear();
    for (auto &i : t)
        i.clear();
    ans.clear();
    t.clear();
    pole.clear();
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}