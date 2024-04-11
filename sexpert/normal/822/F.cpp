#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const double PI = acos(-1);
const int MAXN = 105;

vector<int> adj[MAXN];
int deg[MAXN];
double to[MAXN][MAXN];
vector<ii> edges;

void dfs(int s, int p, double cur) {
    double del = 2.0 / deg[s];
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        cur += del;
        if(cur > 2.0)
            cur -= 2.0;
        if(cur < 1.0)
            to[s][v] = cur;
        else
            to[v][s] = cur - 1.0;
        if(cur < 1.0)
            dfs(v, s, cur + 1.0);
        else
            dfs(v, s, cur - 1.0);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x , y;
        cin >> x >> y;
        edges.push_back({x, y});
        deg[x]++; deg[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            to[i][j] = -1.0;
    dfs(1, 0, PI - 3.0);
    cout << n - 1 << '\n';
    cout << fixed << setprecision(10);
    for(int i = 0; i < n - 1; i++) {
        auto e = edges[i];
        cout << "1 " << i + 1 << " ";
        if(to[e.first][e.second] > -0.5)
            cout << e.first << " " << e.second << " " << to[e.first][e.second] << '\n';
        else
            cout << e.second << " " << e.first << " " << to[e.second][e.first] << '\n';
    }
}