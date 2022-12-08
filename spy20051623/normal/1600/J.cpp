#include <bits/stdc++.h>
using namespace std;
int n, m;
bool mp[1003][1003][4];
bool vis[1003][1003];
vector<int>ans;
int cnt;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(int x,int y) {
    if (vis[x][y]) return;
    cnt++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) {
            if (!vis[dx][dy]) {
                if (i == 0 && !mp[x][y][3]) {
                    dfs(dx,dy);
                }
                if (i == 1 && !mp[x][y][1]) {
                    dfs(dx,dy);
                }
                if (i == 2 && !mp[x][y][2]) {
                    dfs(dx,dy);
                }
                if (i == 3 && !mp[x][y][0]) {
                    dfs(dx,dy);
                }
            }
        }
    }
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cur;
            cin >> cur;
            if (cur & 1) mp[i][j][0] = 1;
            if (cur & 2) mp[i][j][1] = 1;
            if (cur & 4) mp[i][j][2] = 1;
            if (cur & 8) mp[i][j][3] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                cnt = 0;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}