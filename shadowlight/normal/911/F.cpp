#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;

int a = -1, b = -1;

int d = 0;
int n;

pair <int, int> dfs(int v, int p) {
    pair <int, int> pm1 = {-1, -1}, pm2 = {-1, -1};
    bool fl = 0;
    for (int u : gr[v]) {
        if (u == p) continue;
        auto p1 = dfs(u, v);
        fl = 1;
        p1.first++;
        if (p1 > pm1) {
            pm2 = pm1;
            pm1 = p1;
        } else if (p1 > pm2) {
            pm2 = p1;
        }
    }
    if (!fl) {
        return {0, v};
    }
    if (pm2.first != -1 && pm1.first != -1) {
        if (pm2.first + pm1.first > d) {
            d = pm2.first + pm1.first;
            a = pm1.second, b = pm2.second;
        }
    }
    return pm1;
}

vector <int> bfs(int v) {
    vector <int> dist(n, INF);
    dist[v] = 0;
    queue <int> q;
    q.push(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : gr[v]) {
            if (dist[u] != INF) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    return dist;
}

struct Q {
    int a, b, c;
};

vector <pair <int, int> > ans;
vector <int> good;
vector <int> da, db;
ll sum = 0;

void dfs1(int v, int p) {
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs1(u, v);
    }
    if (!good[v]) {
        if (da[v] > db[v]) {
            sum += da[v];
            ans.push_back({a, v});
        } else {
            sum += db[v];
            ans.push_back({b, v});
        }
    }
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
    cin >> n;
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    auto p1 = dfs(0, -1);
    if (gr[0].size() == 1) {
        if (p1.first > d) {
            d = p1.first;
            a = 0, b = p1.second;
        }
    }
    ll res = 0;
    da = bfs(a);
    db = bfs(b);
    good.resize(n);
    for (int v = 0; v < n; v++) {
        if (da[v] + db[v] == d) {
            good[v] = 1;
        }
    }
    dfs1(a, -1);
    int now = b;
    while (now != a) {
        ans.push_back({a, now});
        sum += da[now];
        good[now] = false;
        for (int u : gr[now]) {
            if (good[u]) {
                now = u;
                break;
            }
        }
    }
    cout << sum << "\n";
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << " " << p.second + 1 << "\n";
    }
}