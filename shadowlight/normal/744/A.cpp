#include <bits/stdc++.h>

using namespace std;

vector <int> used;
vector <vector <int> > gr;
vector <int> color;

int cnt;
int reb;
int n, m, k;

void dfs(int v, int col) {
    if (used[v]) return;
    used[v] = 1;
    cnt++;
    color[v] = col;
    for (int i = 0; i < n; i++) {
        if (!gr[v][i]) continue;
        reb++;
        dfs(i, col);
    }
}

int main() {
    cin >> n >> m >> k;
    gr.resize(n, vector <int> (n, 0));
    used.resize(n, 0);
    vector <int> st;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        st.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        gr[l][r] = 1;
        gr[r][l] = 1;
    }
    color.resize(n, 0);
    int maxk = 0;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        cnt = 0;
        reb = 0;
        dfs(st[i], i + 1);
        reb /= 2;
        maxk = max(maxk, cnt);
        //cout << cnt << " " << reb << endl;
        ans += cnt * (cnt - 1) / 2 - reb;
    }
    vector <int> prev;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        ans += maxk;
        for (int j = 0; j < prev.size(); j++) {
            int x = prev[j];
            if (gr[i][x]) continue;
            ans++;
        }
        prev.push_back(i);
    }
    cout << ans;
}