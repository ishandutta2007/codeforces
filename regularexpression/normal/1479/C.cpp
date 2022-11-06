#include <bits/stdc++.h>
using namespace std;

const int N = 40;
struct Edge {
    int a, b, c;

    Edge() {}
    Edge(int a, int b, int c) : a(a), b(b), c(c) {}
};

int L, R;
int n, m;
vector<Edge> edges;
int x;
int cur_end;

int add_vertex() {
    return n++;
}

void add_edge(int a, int b, int c) {
    // cerr << a << " " << b << " " << c << "\n";
    edges.emplace_back(a, b, c);
    m++;
}

void x_two_times() {
    // cerr << "x two times\n";
    int u = add_vertex();
    vector<Edge> added;
    added.emplace_back(0, u, x);
    for (auto [a, b, c] : edges) {
        if (a == 0)
            added.emplace_back(u, b, c);
    }
    for (auto [a, b, c] : added) 
        add_edge(a, b, c);
    x *= 2;
}

void x_plus_one() {
    // cerr << "x plus one\n";
    int u = add_vertex();
    add_edge(cur_end, u, 1);
    add_edge(0, u, 1);
    cur_end = u;
    x++;
}

void init() {
    n = 2;
    m = 1;
    edges = {{0, 1, 1}};
    x = 1;
    cur_end = 1;
}

vector<int> g[N];
int pos[N], cur_pos = 0;
bool used[N];

void dfs(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) 
            dfs(u);
    }
    pos[v] = n - cur_pos++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> R;
    init();
    int len = R - L + 1;
    vector<int> way;
    while (len > 1) {
        if (len & 1) {
            way.push_back(1);
            len--;
        } else {
            way.push_back(2);
            len >>= 1;
        }
    }
    reverse(way.begin(), way.end());
    for (int c : way) {
        if (c == 1) 
            x_plus_one();
        else 
            x_two_times();
    }
    if (L > 1) {
        int u = add_vertex();
        add_edge(cur_end, u, L - 1);
        cur_end = u;
    }
    for (auto [a, b, c] : edges)
        g[a].push_back(b);
    for (int i = 0; i < n; i++) {
        if (i != 0) 
            g[0].push_back(i);
        if (i != cur_end)
            g[i].push_back(cur_end);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) 
            dfs(i);
    }
    cout << "YES\n" << n << " " << m << "\n";
    for (auto [a, b, c] : edges) 
        cout << pos[a] << " " << pos[b] << " " << c << "\n";
    return 0;
}