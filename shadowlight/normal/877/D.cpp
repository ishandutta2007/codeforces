#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int n, m, k;
vector <vector <int> > data;
vector <vector <int> > dist;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    cin >> n >> m >> k;
    data.resize(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                data[i][j] = 1;
            }
        }
    }
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--;
    dist.resize(n, vector <int> (m, INF));
    dist[sx][sy] = 0;
    queue <pair <int, int> > q;
    q.push({sx, sy});
    vector <set <int> > exist1(n), exist2(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            exist1[i].insert(j);
            exist2[j].insert(i);
            exist1[i].insert(-1);
            exist2[j].insert(-1);
        }
    }
    exist1[sx].erase(sy);
    exist2[sy].erase(sx);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int vx = p.first, vy = p.second;
        //cout << vx << " " << vy << " " << dist[vx][vy] << "\n";
        auto it = exist1[vx].upper_bound(vy);
        vector <int> erased1, erased2;
        while (it != exist1[vx].end()) {
            if (*it > vy + k) break;
            if (data[vx][*it]) break;
            erased1.push_back(*it);
            it++;
        }
        it = exist1[vx].upper_bound(vy);
        --it;
        while (it != exist1[vx].begin()) {
            if (*it < vy - k) break;
            if (data[vx][*it]) break;
            erased1.push_back(*it);
            it--;
        }
        auto it1 = exist2[vy].upper_bound(vx);
        while (it1 != exist2[vy].end()) {
            if (*it1 > vx + k) break;
            if (data[*it1][vy]) break;
            erased2.push_back(*it1);
            it1++;
        }
        it1 = exist2[vy].upper_bound(vx);
        --it1;
        while (it1 != exist2[vy].begin()) {
            if (*it1 < vx - k) break;
            if (data[*it1][vy]) break;
            erased2.push_back(*it1);
            it1--;
        }
        for (int u : erased1) {
            dist[vx][u] = dist[vx][vy] + 1;
            q.push({vx, u});
            exist1[vx].erase(u);
            exist2[u].erase(vx);
        }
        for (int u : erased2) {
            dist[u][vy] = dist[vx][vy] + 1;
            q.push({u, vy});
            exist1[u].erase(vy);
            exist2[vy].erase(u);
        }
    }
    if (dist[tx][ty] == INF) {
        cout << -1;
        return 0;
    }
    cout << dist[tx][ty];
}