#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

vector <vector <char> > a;
int n, m, p;

bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#';
}

const int D = 4;
vector <int> dx = {0, -1, 0, 1};
vector <int> dy = {1, 0, -1, 0};

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
    cin >> n >> m >> p;
    a.resize(n, vector <char> (m));
    vector <int> sp(p);
    for (int i = 0; i < p; i++) {
        cin >> sp[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    pair <int, int> speed[n][m][p];
    set <pair <pair <int, int>, pair <int, int> > > q[p];
    for (int now = 0; now < p; now++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] - '1' != now) {
                    speed[i][j][now] = {INF, INF};
                } else {
                    speed[i][j][now] = {0, 0};
                    q[now].insert({speed[i][j][now], {i, j}});
                }
            }
        }
    }
    int tt = 0;
    while (true) {
        //cout << tt << "\n";
        for (int now = 0; now < p; now++) {
            while (!q[now].empty()) {
                auto t = *q[now].begin();
                int x = t.second.first, y = t.second.second;
                pair <int, int> upd = speed[x][y][now];
                if (upd.second == sp[now]) {
                    upd.second = 1;
                    upd.first++;
                } else {
                    upd.second++;
                }
                if (upd.first > tt) break;
                q[now].erase(q[now].begin());
                for (int d = 0; d < D; d++) {
                    int x1 = x + dx[d], y1 = y + dy[d];
                    if (!isCorrect(x1, y1)) continue;
                    bool fl = true;
                    for (int pr = 0; pr < p; pr++) {
                        if (pr == now) continue;
                        if (speed[x1][y1][pr].first != INF) {
                            fl = false;
                            break;
                        }
                    }
                    if (!fl) continue;
                    if (upd < speed[x1][y1][now]) {
                        q[now].erase({speed[x1][y1][now], {x1, y1}});
                        speed[x1][y1][now] = upd;
                        q[now].insert({speed[x1][y1][now], {x1, y1}});
                    }
                }
            }
        }
        bool fl = false;
        for (int i = 0; i < p; i++) {
            if (!q[i].empty()) {
                fl = true;
                break;
            }
        }
        if (!fl) break;
        tt++;
    }
    vector <int> res(p, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= '1' && a[i][j] <= '9') {
                res[a[i][j] - '1']++;
                continue;
            }
            int who = -1;
            int mink = INF;
            for (int t = 0; t < p; t++) {
                if (mink > speed[i][j][t].first) {
                    mink = speed[i][j][t].first;
                    who = t;
                }
            }
            if (who != -1) {
                res[who]++;
            }
        }
    }
    for (int i = 0; i < p; i++) {
        cout << res[i] << " ";
    }
}