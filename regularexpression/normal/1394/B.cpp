#include<bits/stdc++.h>
using namespace std;

#define sz(a) ((int) (a).size())

const int N = 202020;

int n, m, k;
vector<int> out[N], in[N];
int u[N], v[N], w[N], need;
int pos[N];
int by_ij[9][9];
int color[N];
bool bad[45][45];
int cnt_color[N];
int c[9];
int pos_c;
int ans;
int cur_edge;
int cls[9];

void rec() {
    if (pos_c == k) {
        bool ok = cur_edge == need;
        for (int i = 0; i < k; ++i) cls[i] = by_ij[i][c[i]];
        for (int i = 0; i < k; ++i) {
            for (int j = i; j < k; ++j) ok &= !bad[cls[i]][cls[j]] && !bad[cls[j]][cls[i]];
        }
        if (ok) ++ans;
    } else {
        for (int j = 0; j <= pos_c; ++j) {
            int cur_cnt = cnt_color[by_ij[pos_c][j]];
            cur_edge += cur_cnt;
            c[pos_c] = j;
            ++pos_c;
            rec();
            --pos_c;
            cur_edge -= cur_cnt;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        --u[i];
        --v[i];
        out[u[i]].push_back(i);
        in[v[i]].push_back(i);
    }
    int cur = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= i; ++j) by_ij[i][j] = cur++;
    }
    for (int i = 0; i < n; ++i) {
        if (!out[i].empty()) {
            ++need;
            sort(out[i].begin(), out[i].end(), [&] (int x, int y) {
                return w[x] < w[y];
            });
            for (int j = 0; j < sz(out[i]); ++j) {
                pos[out[i][j]] = j;
                color[out[i][j]] = by_ij[sz(out[i]) - 1][j];
            }
            for (int j = 0; j < sz(out[i]); ++j) {
                for (int to = j + 1; to < sz(out[i]); ++to) bad[color[out[i][j]]][color[out[i][to]]] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto &j : in[i]) j = color[j];
        sort(in[i].begin(), in[i].end());
        for (int j = 0; j + 1 < sz(in[i]); ++j) {
            if (in[i][j] == in[i][j + 1]) bad[in[i][j]][in[i][j]] = 1;
        }
        in[i].erase(unique(in[i].begin(), in[i].end()), in[i].end());
        for (int j = 0; j < sz(in[i]); ++j) {
            for (int to = j + 1; to < sz(in[i]); ++to) bad[in[i][j]][in[i][to]] = 1;
        }
    }
    for (int i = 0; i < m; ++i) ++cnt_color[color[i]];
    rec();
    cout << ans;
    return 0;
}