#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1e5 + 10;
int used[MAXN];
vector<ii> path;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> ans = grid;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int ro = -1, co = -1;
    vector<int> rm, cm;
    for(int i = 0; i < n; i++) {
        int curm = 0;
        for(int j = 0; j < m; j++)
            curm = max(curm, grid[i][j]);
        rm.push_back(curm);
    }
    for(int j = 0; j < m; j++) {
        int curm = 0;
        for(int i = 0; i < n; i++)
            curm = max(curm, grid[i][j]);
        cm.push_back(curm);
    }
    sort(rm.begin(), rm.end());
    sort(cm.begin(), cm.end());
    /*for(auto x : rm)
        cout << x << " ";
    cout << '\n';
    for(auto x : cm)
        cout << x << " ";
    cout << '\n';*/
    while(rm.size() || cm.size()) {
        int tk = 0;
        if(rm.size())
            tk = max(tk, rm.back());
        if(cm.size())
            tk = max(tk, cm.back());
        used[tk] = 1;
        if(rm.size() && rm.back() == tk) {
            rm.pop_back();
            ro++;
        }
        if(cm.size() && cm.back() == tk) {
            cm.pop_back();
            co++;
        }
        path.push_back({ro, co});
        ans[ro][co] = tk;
    }
    vector<int> cand;
    for(int i = 1; i <= n * m; i++)
        if(!used[i])
            cand.push_back(i);
    int cptr = 0;
    reverse(path.begin(), path.end());
    for(auto p : path) {
        int R = p.first, C = p.second;
        for(int i = 0; i < R; i++) {
            if(ans[i][C] == 0)
                ans[i][C] = cand[cptr++];
        }
        for(int j = 0; j < C; j++) {
            if(ans[R][j] == 0)
                ans[R][j] = cand[cptr++];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}