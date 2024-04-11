#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

const int D = 4;
vector <int> dx = {0, 0, 1, -1};
vector <int> dy = {1, -1, 0, 0};

int n, m;

bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
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
    cin >> n >> m;
    int r, c;
    cin >> r >> c;
    r--, c--;
    int ma, mb;
    cin >> ma >> mb;
    vector <vector <char> > a(n, vector <char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector <vector <int> > dp(n, vector <int> (m, INF));
    deque <pair <int, int> > q;
    dp[r][c] = 0;
    q.push_back({r, c});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop_front();
        for (int d = 0; d < D; d++) {
            int x1 = dx[d] + x, y1 = dy[d] + y;
            if (!isCorrect(x1, y1) || a[x1][y1] == '*') continue;
            if (d > 2) {
                if (dp[x1][y1] <= dp[x][y]) continue;
                dp[x1][y1] = dp[x][y];
                q.push_front({x1, y1});
            } else {
                int now = dp[x][y];
                if (d == 1) {
                    now++;
                }
                if (dp[x1][y1] <= now) continue;
                dp[x1][y1] = now;
                if (x == c) {
                    q.push_front({x1, y1});
                    continue;
                }
                q.push_back({x1, y1});
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] > ma) {
                continue;
            }
            int sum = j - c + dp[i][j];
            if (sum > mb) continue;
            res++;
            //cout << i << " " << j << "\n";
        }
    }
    cout << res;
}