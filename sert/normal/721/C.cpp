#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const int INF = (ll)1e9 + 34;

int t[5002][5002];
int p[5002][5002];
vector <pair<int, int> > es[5002];

int main() {
    init();
    int n, m, T, v1, v2, c;
    cin >> n >> m >> T;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> c;
        es[v1 - 1].push_back({v2 - 1, c});
    }

    for (int i = 0; i < n; i++)
        for (int k = 0; k <= n; k++) {
            t[i][k] = INF;
            p[i][k] = -1;
        }

    t[0][1] = 0;

    for (int k = 1; k < n; k++)
        for (int i = 0; i < n; i++) {
            if (t[i][k] == INF) continue;
            for (auto w: es[i]) {
                if (t[w.first][k + 1] > t[i][k] + w.second) {
                    t[w.first][k + 1] = t[i][k] + w.second;
                    p[w.first][k + 1] = i;
                }
            }
        }

    int ans = -1;
    for (int i = 1; i <= n; i++)
        if (t[n - 1][i] <= T)
            ans = i;


    cout << ans << "\n";

    vector <int> path;
    int v = n - 1;
    while (v != -1) {
        path.push_back(v);
        v = p[v][ans--];
    }
    for (int i = (int)path.size() - 1; i >= 0; i--)
        cout << path[i] + 1 << " ";

    return 0;
}