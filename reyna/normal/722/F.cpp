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
const int N = (int) 2e5 + 6, M = 41, mod = (int) 0;
vector<int> pos[N];
int sz[N], a[N][M], pl[N], cnt[N], res[N], lst[M], valid[N], gcd[M][M];
map<int, int> where[N];

void solve(int n, int num) {
    for (int i = 0; i < M; ++i)
        lst[i] = -1;
    for (int i = 0; i < n; ++i)
        valid[i] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; ++j)
            if (lst[j] != -1) {
                int p = lst[j];
                int g = gcd[cnt[i]][cnt[p]];
                if (pl[i] % g != pl[p] % g) {
                    valid[i] = max(valid[i], p + 1);
                } else {
                    valid[i] = max(valid[i], valid[p]);
                }
            }
        res[num] = max(res[num], i - valid[i] + 1);
        lst[cnt[i]] = i;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < M; ++i)
        for (int j = 1; j < M; ++j)
            gcd[i][j] = __gcd(i, j);
    for (int i = 0; i < n; ++i) {
        cin >> sz[i];
        for (int j = 0; j < sz[i]; ++j)
            cin >> a[i][j], a[i][j]--, where[i][a[i][j]] = j, pos[a[i][j]].push_back(i);
    }
    for (int num = 0; num < m; ++num) {
        int r = 0;
        for (int l = 0; l < (int) pos[num].size(); ++l) {
            r = max(l, r);
            while (r < pos[num].size() - 1 && pos[num][r] == pos[num][r + 1] - 1) ++r;
            if (l == 0 || pos[num][l - 1] != pos[num][l] - 1) {
                for (int i = l; i <= r; ++i) {
                    int x = pos[num][i];
                    cnt[i - l] = sz[x];
                    pl[i - l] = where[x][num];
                }
                solve(r - l + 1, num);
            }
        }
    }
    for (int i = 0; i < m; ++i)
        cout << res[i] << '\n';

}