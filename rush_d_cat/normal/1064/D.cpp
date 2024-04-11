#include <bits/stdc++.h>
using namespace std;
struct Nod {
    int x, y, l, r;
};
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int r, c;
    cin >> r >> c;
    r --, c --;
    int X, Y;
    cin >> X >> Y;
    
    vector<string> s(n);
    for (int i = 0; i < n; i ++)
        cin >> s[i];

    auto in = [&](int x, int y) {
        return x<n && x>=0 && y<m && y>=0;
    };
    deque<Nod> q;
    q.push_back((Nod){r, c, 0, 0});
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    vis[r][c] = 1;
    int ans = 0;

    while (q.size()) {
        Nod cur = q.front(); q.pop_front();
        ans ++;
        for (int i = 0; i < 4; i ++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (in(nx, ny) && vis[nx][ny] == 0 && s[nx][ny] == '.') {
                if (i <= 1) q.push_front((Nod){nx, ny, cur.l, cur.r});
                if (i == 2 && cur.l + 1 <= X) q.push_back((Nod){nx, ny, cur.l + 1, cur.r});
                if (i == 3 && cur.r + 1 <= Y) q.push_back((Nod){nx, ny, cur.l, cur.r + 1}); 
                vis[nx][ny] = 1;
            }
        }
    } 
    cout << ans << "\n";
}