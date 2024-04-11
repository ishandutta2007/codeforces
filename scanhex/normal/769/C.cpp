#include <iostream>
#include <deque>

using namespace std;

const int MAXN = 1010;
const int INF = MAXN * MAXN;

char f[MAXN][MAXN];
int d[MAXN][MAXN];

int sx, sy;

// DOWN, LEFT, RIGHT, UP
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", f[i]);
        for (int j = 0; j < m; j++) {
            d[i][j] = INF;
            if (f[i][j] == 'X') {
                sx = i;
                sy = j;
                d[i][j] = 0;
            }
        }
    }

    deque<pair<int, int>> q;
    q.push_back({sx, sy});
    while (!q.empty()) {
        auto u = q.front();
        q.pop_front();
        int ux = u.first, uy = u.second;
        for (int dd = 0; dd < 4; dd++) {
            int vx = ux + dx[dd];
            int vy = uy + dy[dd];
            if (0 <= vx && vx < n && 0 <= vy && vy < m && f[vx][vy] != '*' && d[vx][vy] == INF) {
                d[vx][vy] = d[ux][uy] + 1;
                q.push_back({vx, vy});
            }
        }
    }

    if (k % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    string s = "";
    int x = sx, y = sy;
    for (int i = 0; i < k; i++) {
        bool ok = false;
        for (int dd = 0; dd < 4; dd++) {
            int xx = x + dx[dd];
            int yy = y + dy[dd];
            if (0 <= xx && xx < n && 0 <= yy && yy < m && f[xx][yy] != '*' && d[xx][yy] <= (k - i - 1)) {
                ok = true;
                s.push_back("DLRU"[dd]);
                x = xx;
                y = yy;
                break;
            }
        }

        if (!ok) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << s << endl;

    return 0;
}