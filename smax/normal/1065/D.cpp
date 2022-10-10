#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

int a[10][10], dist[10][10][3], numRep[10][10][3];
pair<int, int> where[101], dp[101][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            where[a[i][j]] = {i, j};
        }

    // 0 - knight
    // 1 - bishop
    // 2 - rook
    dp[1][0] = dp[1][1] = dp[1][2] = {0, 0};
    for (int i=1; i<n*n; i++) {
        memset(dist, -1, sizeof(dist));
//        for (int i=0; i<n; i++)
//            for (int j=0; j<n; j++)
//                for (int k=0; k<3; k++)
//                    cerr << dist[i][j][k] << " ";
//        cerr << "\n";
        priority_queue<pair<pair<int, int>, array<int, 3>>, vector<pair<pair<int, int>, array<int, 3>>>, greater<pair<pair<int, int>, array<int, 3>>>> q;
        dist[where[i].first][where[i].second][0] = dp[i][0].first;
        dist[where[i].first][where[i].second][1] = dp[i][1].first;
        dist[where[i].first][where[i].second][2] = dp[i][2].first;
        numRep[where[i].first][where[i].second][0] = dp[i][0].second;
        numRep[where[i].first][where[i].second][1] = dp[i][1].second;
        numRep[where[i].first][where[i].second][2] = dp[i][2].second;
        q.push({{dp[i][0].first, dp[i][0].second}, {where[i].first, where[i].second, 0}});
        q.push({{dp[i][1].first, dp[i][1].second}, {where[i].first, where[i].second, 1}});
        q.push({{dp[i][2].first, dp[i][2].second}, {where[i].first, where[i].second, 2}});
        while (!q.empty()) {
            int r = q.top().second[0], c = q.top().second[1], t = q.top().second[2];
//            if (i == 8) DEBUG(r, c, t, dist[r][c][t], numRep[r][c][t])
            q.pop();

            for (int j=0; j<3; j++)
                if (dist[r][c][j] == -1 || (dist[r][c][t] + 1 == dist[r][c][j] && numRep[r][c][t] + 1 < numRep[r][c][j])) {
                    dist[r][c][j] = dist[r][c][t] + 1;
                    numRep[r][c][j] = numRep[r][c][t] + 1;
                    q.push({{dist[r][c][j], numRep[r][c][j]}, {r, c, j}});
                }

            if (t == 0) {
                for (int d=0; d<8; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (0 <= nr && nr < n && 0 <= nc && nc < n && (dist[nr][nc][t] == -1 || (dist[r][c][t] + 1 == dist[nr][nc][t] && numRep[r][c][t] < numRep[nr][nc][t]))) {
                        dist[nr][nc][t] = dist[r][c][t] + 1;
                        numRep[nr][nc][t] = numRep[r][c][t];
                        q.push({{dist[nr][nc][t], numRep[nr][nc][t]}, {nr, nc, t}});
                    }
                }
            } else if (t == 1) {
                for (int d=1; d<n; d++)
                    for (int sr : {-1, 1})
                        for (int sc : {-1, 1}) {
                            int nr = r + sr * d, nc = c + sc * d;
                            if (0 <= nr && nr < n && 0 <= nc && nc < n && (dist[nr][nc][t] == -1 || (dist[r][c][t] + 1 == dist[nr][nc][t] && numRep[r][c][t] < numRep[nr][nc][t]))) {
                                dist[nr][nc][t] = dist[r][c][t] + 1;
                                numRep[nr][nc][t] = numRep[r][c][t];
                                q.push({{dist[nr][nc][t], numRep[nr][nc][t]}, {nr, nc, t}});
                            }
                        }
            } else {
                for (int nr=0; nr<n; nr++) {
                    int nc = c;
//                    if (i == 8 && r == 0 && c == 0 && t == 2) DEBUG(nr, nc, dist[nr][nc][t], numRep[nr][nc][t])
                    if (0 <= nr && nr < n && 0 <= nc && nc < n && (dist[nr][nc][t] == -1 || (dist[r][c][t] + 1 == dist[nr][nc][t] && numRep[r][c][t] < numRep[nr][nc][t]))) {
//                        if (i == 8 && r == 0 && c == 0 && t == 2) DEBUG("IN BOYS")
                        dist[nr][nc][t] = dist[r][c][t] + 1;
                        numRep[nr][nc][t] = numRep[r][c][t];
                        q.push({{dist[nr][nc][t], numRep[nr][nc][t]}, {nr, nc, t}});
                    }
                }
                for (int nc=0; nc<n; nc++) {
                    int nr = r;
//                    if (i == 8 && r == 0 && c == 0 && t == 2) DEBUG(nr, nc, dist[nr][nc][t], numRep[nr][nc][t])
                    if (0 <= nr && nr < n && 0 <= nc && nc < n && (dist[nr][nc][t] == -1 || (dist[r][c][t] + 1 == dist[nr][nc][t] && numRep[r][c][t] < numRep[nr][nc][t]))) {
//                        if (i == 8 && r == 0 && c == 0 && t == 2) DEBUG("IN TWO")
                        dist[nr][nc][t] = dist[r][c][t] + 1;
                        numRep[nr][nc][t] = numRep[r][c][t];
                        q.push({{dist[nr][nc][t], numRep[nr][nc][t]}, {nr, nc, t}});
                    }
                }
            }
        }

        dp[i+1][0] = {dist[where[i+1].first][where[i+1].second][0], numRep[where[i+1].first][where[i+1].second][0]};
        dp[i+1][1] = {dist[where[i+1].first][where[i+1].second][1], numRep[where[i+1].first][where[i+1].second][1]};
        dp[i+1][2] = {dist[where[i+1].first][where[i+1].second][2], numRep[where[i+1].first][where[i+1].second][2]};
//        DEBUG(i + 1, dp[i+1][0], dp[i+1][1], dp[i+1][2])
    }

    pair<int, int> ret = min({dp[n*n][0], dp[n*n][1], dp[n*n][2]});

    cout << ret.first << " " << ret.second << "\n";

    return 0;
}