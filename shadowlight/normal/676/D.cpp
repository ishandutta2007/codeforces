#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n, m;
const int D = 4;
vector <int> dy = {0, -1, 0, 1};
vector <int> dx = {-1, 0, 1, 0};
vector <vector <int> > doors;

bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

struct State {
    int x, y, r;
};

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n >> m;
    doors.resize(n, vector <int> (m, 0));
    map <char, int> mask;
    mask['+'] = 15;
    mask['-'] = 10;
    mask['|'] = 5;
    mask['*'] = 0;
    mask['^'] = 1;
    mask['>'] = 8;
    mask['v'] = 4;
    mask['<'] = 2;
    mask['L'] = 13;
    mask['R'] = 7;
    mask['U'] = 14;
    mask['D'] = 11;
    vector <vector <vector <int> > > dp(n, vector <vector <int> > (m, vector <int> (4, INF)));
    queue <State> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            doors[i][j] = mask[c];
        }
    }
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--;
    dp[sx][sy][0] = 0;
    q.push({sx, sy, 0});
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        int x = v.x, y = v.y, r = v.r;
        //cout << x << " " << y << " " << r << " " << dp[x][y][r] << "\n";
        for (int d = 0; d < D; d++) {
            int x1 = dx[d] + x, y1 = dy[d] + y;
            if (!isCorrect(x1, y1)) continue;
            int mv1 = (d + r) % 4;
            if ((doors[x][y] & (1 << mv1)) == 0) continue;
            int mv2 = (d + 2 + r) % 4;
            if ((doors[x1][y1] & (1 << mv2)) == 0) continue;
            //cout << x << " " << y << " " << d << " " << r << " " << mv1 << " " << mv2 << "\n";
            if (dp[x1][y1][r] == INF) {
                dp[x1][y1][r] = dp[x][y][r] + 1;
                q.push({x1, y1, r});
            }
        }
        if (dp[x][y][(r + 1) % 4] == INF) {
            dp[x][y][(r + 1) % 4] = dp[x][y][r] + 1;
            q.push({x, y, (r + 1) % 4});
        }
    }
    int mink = INF;
    for (int i = 0; i < 4; i++) {
        mink = min(mink, dp[tx][ty][i]);
    }
    cout << (mink == INF ? -1 : mink);
}