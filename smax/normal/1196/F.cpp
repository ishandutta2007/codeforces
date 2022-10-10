#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

long long dist[800][800];
pair<int, pair<int, int>> edges[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++)
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;

    sort(edges, edges + m);
    memset(dist, -1, sizeof(dist));

    int idx = 0;
    unordered_map<int, int> encode;
    for (int i=0; i<min(m,k); i++) {
        if (!encode.count(edges[i].second.first))
            encode[edges[i].second.first] = idx++;
        if (!encode.count(edges[i].second.second))
            encode[edges[i].second.second] = idx++;
        int x = encode[edges[i].second.first], y = encode[edges[i].second.second];
        dist[x][y] = dist[y][x] = edges[i].first;
    }

    for (int i=0; i<idx; i++)
        for (int j=0; j<idx; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (dist[i][j] == -1)
                dist[i][j] = INF;
        }

    for (int kk=0; kk<idx; kk++)
        for (int i=0; i<idx; i++)
            for (int j=0; j<idx; j++)
                dist[i][j] = min(dist[i][j], dist[i][kk] + dist[kk][j]);

    vector<long long> ret;
    for (int i=0; i<idx; i++)
        for (int j=i+1; j<idx; j++)
            ret.push_back(dist[i][j]);

    sort(ret.begin(), ret.end());

    cout << ret[k-1] << "\n";

    return 0;
}