#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;
const int Q = 16;

vector <vector <int> > gr;

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
    int n, m;
    cin >> n >> m;
    vector <vector <int> > a(n, vector <int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1) {
        int res = INF;
        for (int i = 0; i < m - 1; i++) {
            res = min(res, abs(a[0][i] - a[0][i + 1]));
        }
        cout << res << "\n";
        return 0;
    }
    gr.resize(n, vector <int> (n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < m; k++) {
                gr[i][j] = min(gr[i][j], abs(a[i][k] - a[j][k]));
            }
        }
    }
    int N = 1 << n;
    vector <vector <vector <int> > > res(N, vector <vector <int> > (n, vector <int> (n, 0)));
    for (int i = 0; i < n; i++) {
        res[1 << i][i][i] = INF;
    }
    for (int mask = 0; mask < N; mask++) {
        for (int st = 0; st < n; st++) {
            for (int last = 0; last < n; last++) {
                if (!(mask & (1 << st)) || !(mask & (1 << last))) continue;
                for (int nxt = 0; nxt < n; nxt++) {
                    if (mask & (1 << nxt)) continue;
                    int mask1 = mask | (1 << nxt);
                    res[mask1][st][nxt] = max(res[mask1][st][nxt], min(res[mask][st][last], gr[last][nxt]));
                }
            }
        }
    }
    int ans = 0;
    for (int st = 0; st < n; st++) {
        for (int last = 0; last < n; last++) {
            if (st == last) continue;
            int now = res[N - 1][st][last];
            for (int i = 0; i < m - 1; i++) {
                now = min(now, abs(a[last][i] - a[st][i + 1]));
            }
            ans = max(ans, now);
        }
    }
    cout << ans;
}