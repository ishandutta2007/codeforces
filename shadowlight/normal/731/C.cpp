#include <bits/stdc++.h>

using namespace std;

vector <int> color;
vector <vector <int> > neighbours;
vector <int> used;
map <int, int> cnt_of_colors;
int max_cnt, cnt;

void dfs(int v) {
    if (used[v]) return;
    used[v] = 1;
    if (cnt_of_colors.find(color[v]) == cnt_of_colors.end()) {
        cnt_of_colors[color[v]] = 1;
    } else {
        cnt_of_colors[color[v]]++;
    }
    max_cnt = max(max_cnt, cnt_of_colors[color[v]]);
    cnt++;
    for (int i = 0; i < neighbours[v].size(); i++) {
        dfs(neighbours[v][i]);
    }
}
int main() {
    int n, m, k;
    int ans = 0;
    cin >> n >> m >> k;
    color.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        color.push_back(x);
    }
    neighbours.resize(n + 1);
    used.resize(n + 1, 0);
    int max_sum = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        neighbours[l].push_back(r);
        neighbours[r].push_back(l);
    }
    for (int i = 1; i <= n; i++) {
        cnt_of_colors.clear();
        max_cnt = 0;
        cnt = 0;
        if (!used[i]) {
            dfs(i);
        }
        //cout << cnt << " " << max_cnt << endl;
        ans += cnt - max_cnt;
    }
    cout << ans << endl;
}