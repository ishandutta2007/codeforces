#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = (int)1e9+7;

int n, m, s, l;
vector<vector<pii>> r;
vector<int> dist;
int ans = 0;

void d_step(priority_queue<pii>& steps, int v, int ndist) {
    dist[v] = ndist;
    if (ndist == l) {
        return;
    }
    if (dist[v] >= l) {
        return;
    }
    //cout << v << ", " << ndist << '\n';
    for (int i = 0; i < r[v].size(); ++i) {
        if (dist[r[v][i].first] > dist[v] + r[v][i].second) {
            steps.push({INF - (dist[v] + r[v][i].second), r[v][i].first});
        }
    }
}

void dijkstra() {
    priority_queue<pii> ask;
    ask.push({INF, s});
    while (!ask.empty()) {
        int nextv = ask.top().second;
        int cd = INF - ask.top().first;
        ask.pop();
        if (dist[nextv] > cd) {
            d_step(ask, nextv, cd);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s;
    r.resize(n);
    --s;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        r[u].push_back({v, w});
        r[v].push_back({u, w});
    }
    dist.assign(n, INF);
    cin >> l;

    dijkstra();

    for (int i = 0; i < n; ++i) {
        if (dist[i] == l) {
            ++ans;
        } else if (dist[i] < l) {
            for (int j = 0; j < r[i].size(); ++j) {
                if (dist[r[i][j].first] >= l && dist[i] + r[i][j].second > l) {
                    ++ans;
                } else if (l * 2 == dist[i] + dist[r[i][j].first] + r[i][j].second && dist[i] + r[i][j].second > l) {
                    if (i < r[i][j].first) {
                        ++ans;
                    }
                } else if (l * 2 < dist[i] + dist[r[i][j].first] + r[i][j].second && dist[i] + r[i][j].second > l) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}