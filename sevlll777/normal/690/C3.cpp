#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <map>
#include <set>
#include <deque>

#define pb push_back
#define int long long
#define pii pair<int, int>
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1e9 + 7;
vector<int> heh(21, -1);
unordered_map<int, int> par;
vector<vector<int>> up(1e6, heh);
vector<int> depth(1e6, -1);


int lca(int v1, int v2) {
    if (depth[v2] > depth[v1]) {
        swap(v1, v2);
    }
    int x = depth[v1] - depth[v2];
    for (int j = 20; j >= 1; j--) {
        if (x >= (1 << (j - 1))) {
            v1 = up[v1][j];
            x -= (1 << (j - 1));
        }
    }
    for (int j = 20; j >= 1; j--) {
        if (up[v1][j] != up[v2][j]) {
            v1 = up[v1][j];
            v2 = up[v2][j];
        }
    }
    return up[v1][1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        up[i][0] = i;
    }
    for (int j = 0; j < 21; j++) {
        up[0][j] = 0;
    }
    depth[0] = 0;
    par[0] = -1;
    int y1 = 0, y2 = 0;
    int now_ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        int p; cin >> p; p--;
        par[i] = p;
        depth[i] = depth[p] + 1;
        up[i][0] = i;
        up[i][1] = p;
        for (int j = 2; j < 21; j++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
        int num1 = depth[y1] + depth[i] - 2 * depth[lca(y1, i)];
        int num2 = depth[y2] + depth[i] - 2 * depth[lca(y2, i)];
        if (now_ans < num1) {
            now_ans = num1;
            y2 = i;
        } else if (now_ans < num2) {
            now_ans = num2;
            y1 = i;
        }
        cout << now_ans << ' ';
    }
}