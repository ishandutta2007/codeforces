#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int N = 15;
int n;

pair <int, int> cnt[3][3][N * N][N * N];

bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

const int D[3] = {8, 4, 4};
vector <int> dx[3], dy[3];

void init() {
    dx[0] = {-2, -2, -1, -1, 1, 1, 2, 2};
    dy[0] = {-1, 1, -2, 2, -2, 2, -1, 1};
    dx[1] = {-1, -1, 1, 1};
    dy[1] = {-1, 1, -1, 1};
    dx[2] = {-1, 0, 1, 0};
    dy[2] = {0, -1, 0, 1};
}

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
    init();
    cin >> n;
    vector <int> pos(n * n);
    for (int i = 0; i < n * n; i++) {
        ll x;
        cin >> x;
        x--;
        pos[x] = i;
    }
        for (int s = 0; s < n * n; s++) {
            for (int st = 0; st < 3; st++) {
                vector <vector <pair <int, int> > > dist(n * n, vector <pair <int, int> > (3, {INF, INF}));
                deque <pair <int, int> > q;
                q.push_back({s, st});
                dist[s][st] = {0, 0};
                while (!q.empty()) {
                    int v = q.front().first;
                    int now = q.front().second;
                    q.pop_front();
                    int x = v / n, y = v % n;
                    pair <int, int> upd = {dist[v][now].first + 1, dist[v][now].second};
                    for (int d = 0; d < D[now]; d++) {
                        int x1 = x + dx[now][d], y1 = y + dy[now][d];
                        while (isCorrect(x1, y1)) {
                            int u = x1 * n + y1;
                            if (dist[u][now] > upd) {
                                dist[u][now] = upd;
                                q.push_front({u, now});
                            }
                            if (!now) break;
                            x1 += dx[now][d];
                            y1 += dy[now][d];
                        }
                    }
                    upd.second++;
                    for (int i = 0; i < 3; i++) {
                        if (dist[v][i] > upd) {
                            dist[v][i] = upd;
                            q.push_back({v, i});
                        }
                    }
                }
                for (int t = 0; t < n * n; t++) {
                    for (int now = 0; now < 3; now++) {
                        cnt[st][now][s][t] = dist[t][now];
                    }
                }
            }
        }
    vector <vector <pair <int, int> > > dp(n * n, vector <pair <int, int> > (3, {INF, INF}));
    for (int i = 0; i < 3; i++) {
        dp[0][i] = {0, 0};
    }
    for (int i = 0; i < n * n - 1; i++) {
        int v = pos[i], u = pos[i + 1];
        for (int st = 0; st < 3; st++) {
            for (int last = 0; last < 3; last++) {
                pair <int, int> now = dp[i][st];
                now.first += cnt[st][last][pos[i]][pos[i + 1]].first;
                now.second += cnt[st][last][pos[i]][pos[i + 1]].second;
                //cout << now.first << " " << now.second << "\n";
                if (dp[i + 1][last] > now) {
                    dp[i + 1][last] = now;
                }
            }
        }
    }
    pair <int, int> res = {INF, INF};
    for (int i = 0; i < 3; i++) {
        res = min(res, dp[n * n - 1][i]);
    }
    cout << res.first << " " << res.second << "\n";
}