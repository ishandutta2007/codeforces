#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        vector<int> id;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') id.push_back(j);
        }
        for (int j = 1; j < id.size(); j++) {
            if (id[j] != id[j - 1] + 1) return puts("-1"),0;
        }
    }
    for (int i = 0; i < m; i++) {
        vector<int> id;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == '#') id.push_back(j);
        }
        for (int j = 1; j < id.size(); j++) {
            if (id[j] != id[j - 1] + 1) return puts("-1"),0;
        }
    }
    int ans = 0;
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};
    vector<int> vis1(n, 0), vis2(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                vis1[i] = 1;
                vis2[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.' && !vis1[i] && !vis2[j]) {
                s[i][j] = '?';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '?') {
                vis1[i] = 1;
                vis2[j] = 1;
                s[i][j] = '.';
            }
        }
    }
    for (int i = 1; i < n; i++) vis1[i] += vis1[i - 1];
    for (int i = 1; i < m; i++) vis2[i] += vis2[i - 1];
    if (vis1[n - 1] != n || vis2[m - 1] != m) return 0 * puts("-1");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                ans++;
                queue<pii> q;
                q.emplace(i, j);
                s[i][j] = '.';
                while(!q.empty()) {
                    auto now = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = now.first + dx[dir];
                        int ny = now.second + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (s[nx][ny] != '#') continue;
                        q.emplace(nx, ny);
                        s[nx][ny] = '.';
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}