#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 34;
const ll INF = 1e9;

ll n, m, k, v1, v2, a, b;
vector <ll> es[N];
ll d[N], pr[N], nx[N];
bool ud[N], term[N];
ll c[N], z[N], vond[N], ans;

void bfs(int st) {
    queue <int> q;
    int v;
    for (int i = 0; i < n; i++) d[i] = -1;
    d[st] = 0;
    q.push(st);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        if (term[v]) b = v;
        for (int i = 0; i < es[v].size(); i++)
            if (d[es[v][i]] == -1) {
                pr[es[v][i]] = v;
                d[es[v][i]] = d[v] + 1;
                q.push(es[v][i]);
            }
    }   
}

void bfs01(int st) {
    deque <int> q;
    int v;
    for (int i = 0; i < n; i++) d[i] = -1;
    d[st] = 0;
    vond[st] = st;
    q.push_back(st);
    while (!q.empty()) {
        v = q.front();
        q.pop_front();
        for (int i = 0; i < es[v].size(); i++) {
            if (d[es[v][i]] != -1)
                continue;
            if (ud[v] && ud[es[v][i]]) {
                q.push_front(es[v][i]);
                d[es[v][i]] = d[v];
                vond[es[v][i]] = es[v][i];
            } else {
                q.push_back(es[v][i]);
                d[es[v][i]] = d[v] + 1;
                vond[es[v][i]] = vond[v];
            }
        }
    }
}

void dfs(int v, int dst) {
    ans++;
    //cout << v + 1 << "  <- a place for a book\n";
    if (dst == 0) 
        return;
    ud[v] = true;
    for (int i = 0; i < es[v].size(); i++)
        if (!ud[es[v][i]])
            dfs(es[v][i], dst - 1);
}

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    int x;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> x;
        term[x - 1] = true;
    }
    for (int i = 1; i < n; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    bfs(0);
    a = b;
    bfs(a);
    int v = b;
    ud[v] = true;
    c[v] = INF;

    //cerr << "bfs\n";

    //cout << "diametr: " << v + 1;

    while (v != a) {
        nx[pr[v]] = v;
        v = pr[v];
        //cout << " " << v + 1;
        c[v] = INF;
        ud[v] = true;
    }
    //cout << "\n";

    bfs01(a);

    //cerr << "01bfs\n";

    for (int i = 0; i < n; i++)
        z[i] = INF;

    for (int i = 0; i < n; i++)
        if (term[i]) 
            z[vond[i]] = k - d[i];
        
    ll cur = z[a];
    v = a;
    c[a] = cur;
    while (v != b) {
        v = nx[v];
        cur = min(cur - 1, z[v]);
        c[v] = cur;
    }

    cur = z[b];
    v = b;
    c[b] = min(c[b], cur);
    //cout << "distans: " << c[v];
    while (v != a) {
        v = pr[v];
        cur = min(cur - 1, z[v]);
        c[v] = min(c[v], cur);
        //cout << " " << c[v];
    }
    //cout << "\n";

    v = a;

    //cerr << "pre dfss\n";

    if (c[v] >= 0) dfs(v, c[v]);
    while (v != b) {
        if (c[v] >= 0) dfs(v, c[v]);
        v = nx[v];
    }

    cout << ans;

    return 0;
}