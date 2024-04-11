#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<pii>> c(p + 1, vector<pii>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            c[a].push_back(make_pair(i, j));
        }
    }

    vector<vector<ll>> d(n, vector<ll>(m, 1000000000000LL));
    vector<vector<ll>> d2(n, vector<ll>(m, 1000000000000LL));
    vector<bool> inuse(n, false);
    inuse[0] = true;
    for (int j = 0; j < m; ++j) {
        d[0][j] = j;
    }

    for (int q = 1; q <= p; ++q) {
        for (int v = 0; v < c[q].size(); ++v) {
            int cx = c[q][v].first;
            int cy = c[q][v].second;
            ll mint = 1000000000000LL;
            for (int i = 0; i < n; ++i) {
                if (!inuse[i]) {
                    continue;
                }
                mint = min(mint, d[i][cy] + abs(i - cx));
            }
            if (d2[cx][cy] > mint) {
                d2[cx][cy] = mint;
                for (int jl = cy - 1; jl >= 0; --jl) {
                    d2[cx][jl] = min(d2[cx][jl], d2[cx][jl + 1] + 1);
                }
                for (int jr = cy + 1; jr < m; ++jr) {
                    d2[cx][jr] = min(d2[cx][jr], d2[cx][jr - 1] + 1);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            inuse[i] = false;
        }
        for (int v = 0; v < c[q].size(); ++v) {
            int cx = c[q][v].first;
            int cy = c[q][v].second;
            if (inuse[cx]) {
                continue;
            }
            inuse[cx] = true;
            for (int j = 0; j < m; ++j) {
                d[cx][j] = d2[cx][j];
                d2[cx][j] = 1000000000000LL;
            }
        }
    }

    int px = c[p][0].first;
    int py = c[p][0].second;
    cout << d[px][py] << '\n';

    return 0;
}