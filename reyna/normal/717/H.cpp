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
const int N = (int) 1e6 + 6, mod = (int) 0;
int k, len[N], tt[N][20], g[N], s[N], t[N], pl[N];
vector<int> adj[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(49);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int &u = s[i], &v = t[i];
        cin >> u >> v;
        --u, --v;
    }
    for (int i = 0; i < n; ++i) {
        cin >> len[i];
        for (int j = 0; j < len[i]; ++j) {
            cin >> tt[i][j];
            tt[i][j]--;
            k = max(k, tt[i][j] + 1);
        }
    }
    while (true) {
        for (int i = 0; i < k; ++i)
            adj[i].clear();
        for (int i = 0; i < n; ++i) {
            int team = rand() % len[i];
            g[i] = tt[i][team];
        }
        for (int i = 0; i < m; ++i) {
            int u = s[i];
            int v = t[i];
            if (g[u] != g[v]) {
                int x = g[u];
                int y = g[v];
                if (x > y)
                    swap(x, y);
                adj[y].push_back(x);
            }
        }
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            int cnt0 = 0, cnt1 = 0;
            for (int x : adj[i]) {
                if (pl[x])
                    cnt0++;
                else
                    cnt1++;
            }
            if (cnt0 >= cnt1)
                pl[i] = 0;
            else
                pl[i] = 1;
            cnt += max(cnt0, cnt1);
        }
        if (cnt >= m / 2 + m % 2) {
            for (int i = 0; i < n; ++i) cout << g[i] + 1 << ' ';
            cout << endl;
            for (int i = 0; i < k; ++i) cout << pl[i] + 1 << ' ';
            return 0;
        }


    }






}