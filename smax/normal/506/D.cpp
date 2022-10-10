#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
#define SZ 450

int parent[MAX], Size[MAX];

void init(int n) {
    for (int i=0; i<n; i++) {
        parent[i] = i;
        Size[i] = 1;
    }
}

int Find(int u) {
    if (u != parent[u])
        parent[u] = Find(parent[u]);
    return parent[u];
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
        if (Size[u] < Size[v])
            swap(u, v);
        parent[v] = u;
        Size[u] += Size[v];
    }
}

int qa[MAX], qb[MAX], big[MAX], table[SZ][MAX] = {};
bool visited[MAX] = {}, match[MAX] = {};
vector<int> bigVertices, temp[MAX], appear[MAX];
vector<vector<int>> comp;
vector<pair<int, int>> edges[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        edges[c].emplace_back(a, b);
    }

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> qa[i] >> qb[i];
        qa[i]--, qb[i]--;
    }

    init(n);
    for (int c=0; c<m; c++) {
        for (auto e : edges[c])
            Union(e.first, e.second);
        for (auto e : edges[c]) {
            if (!visited[e.first]) {
                temp[Find(e.first)].push_back(e.first);
                visited[e.first] = true;
            }
            if (!visited[e.second]) {
                temp[Find(e.second)].push_back(e.second);
                visited[e.second] = true;
            }
        }
        for (auto e : edges[c]) {
            if (!temp[e.first].empty()) {
                comp.push_back(temp[e.first]);
                temp[e.first].clear();
            }
            if (!temp[e.second].empty()) {
                comp.push_back(temp[e.second]);
                temp[e.second].clear();
            }

            visited[e.first] = visited[e.second] = false;
            parent[e.first] = e.first, parent[e.second] = e.second;
            Size[e.first] = Size[e.second] = 1;
        }
    }

    for (int i=0; i<comp.size(); i++)
        for (int j=0; j<comp[i].size(); j++)
            appear[comp[i][j]].push_back(i);
    for (int i=0; i<n; i++) {
        if (appear[i].size() > SZ) {
            big[i] = bigVertices.size();
            bigVertices.push_back(i);
        } else
            big[i] = -1;
    }

    for (int i=0; i<bigVertices.size(); i++)
        for (int c : appear[bigVertices[i]])
            for (int j : comp[c])
                table[i][j]++;

    for (int i=0; i<q; i++) {
        int a = qa[i], b = qb[i];
        if (big[a] == -1)
            swap(a, b);
        if (big[a] != -1)
            cout << table[big[a]][b] << "\n";
        else {
            int ret = 0;
            for (int c : appear[a])
                match[c] = true;
            for (int c : appear[b])
                ret += match[c];
            for (int c : appear[a])
                match[c] = false;
            cout << ret << "\n";
        }
    }

    return 0;
}