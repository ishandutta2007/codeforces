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

const int N = (int) 2e5 + 5, M = 1005, mod = 0;

int s[N], t[N], ql[N], qr[N], res[N], qs[N], qt[N], mat[M][M];
vector<int> pro[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> t[i];
        s[i]--;
        t[i]--;
    }
    memset(mat, 63, sizeof mat);
    for (int i = 0; i < n; ++i)
        mat[i][i] = 0;
    for (int i = 0; i < q; ++i) {
        cin >> ql[i] >> qr[i] >> qs[i] >> qt[i];
        ql[i]--;
        qr[i]--;
        qs[i]--;
        qt[i]--;
        pro[ql[i]].push_back(i);
    }
    for (int i = m - 1; i >= 0; --i) {
        int xu = s[i], xv = t[i];
        mat[xu][xv] = mat[xv][xu] = i;
        for (int j = 0; j < n; ++j) {
            int p = min(mat[xv][j], mat[xu][j]);
            mat[xv][j] = max(i, p);
            mat[xu][j] = max(i, p);
        }
        mat[xu][xu] = 0;
        mat[xv][xv] = 0;
        for (int x : pro[i]) {
            int u = qs[x], v = qt[x], r = qr[x];
            if (mat[u][v] <= r) {
                res[x] = 1;
            }
        }
    }
    for (int i = 0; i < q; ++i)
        cout << (res[i]? "Yes": "No") << '\n';



}