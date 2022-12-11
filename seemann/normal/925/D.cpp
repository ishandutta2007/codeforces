#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const int MAXN = 3e5 + 100;

bool used[MAXN];
int dist[MAXN];
int pr[MAXN];
vector<int> e[MAXN];
vector<int> comp, ans;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    used[v] = true;
    dist[v] = 0;
    pr[v] = -1;
    comp.pb(v);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto v : e[cur]) {
            if (used[v]) {
                continue;
            }
            used[v] = true;
            dist[v] = dist[cur] + 1;
            pr[v] = cur;
            comp.pb(v);
            q.push(v);
        }
    }
}

/*
void dfs(int v, int prev = -1) {
    used[v] = true;
    pr[v] = prev;
    comp.pb(v);
    for (auto u : e[v]) {
        if (used[u])
            continue;
        dfs(u, v);
    }
}*/

pair<int, int> findNonEdge(const vector<int>& a, vector<int>&b) {
    sort(b.begin(), b.end());
    /*
    cerr << "NON ";
    for (auto v : a) {
        cerr << v << ' ';
    }
    cerr << '\n';
    for (auto v : b) {
        cerr << v << ' ' ;
    }
    cerr << '\n';*/
    for (auto v : a) {
        int p = 0;
        for (auto u : e[v]) {
            while (p < b.size() && b[p] == v) {
                p++;
            }
            if (p < b.size() && b[p] < u) {
                return {v, b[p]};
            } else {
                p++;
            }
        }
        while (p < b.size() && b[p] == v) {
            p++;
        }
        if (p < b.size()) {
            return {v, b[p]};
        }
    }

    return {-1, -1};
}

void rest(int v) {
    vector<int> path;
    while (v != -1) {
        path.pb(v);
        v = pr[v];
    }
    reverse(path.begin(), path.end());
    for (auto x : path) {
        ans.pb(x);
    }
}

void printans() {
    cout << ans.size() - 1<< '\n';
    for (auto x : ans) {
        cout << x + 1<< ' ';
    }
    cout << '\n';
}

int main() {
#ifdef LOCAL
//    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].pb(v);
        e[v].pb(u);
    }
    forn(i,n) {
        sort(e[i].begin(), e[i].end());
    }

    bfs(0);
    
    if (used[n - 1]) {
        rest(n - 1);
        if (ans.size() <= 5) {
            printans();
            return 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (used[i] && dist[i] == 2) {
            ans.clear();
            ans.pb(0);
            ans.pb(pr[i]);
            ans.pb(i);
            ans.pb(0);
            ans.pb(n - 1);
            printans();
            return 0;
        }
    }

    for(int i = 1; i < n; ++i) {
        if (e[i].size() > 0 && e[i][0] == 0)
            e[i].erase(e[i].begin());
    }

    clr(used);
    clr(dist);
    clr(pr);
    vector<int> stcomp = comp;
    for (auto x : stcomp) {
        if (x == 0 || used[x]) {
            continue;
        }
        comp.clear();
        bfs(x);
        for (auto v : comp) {
            if (dist[v] == 2) {
                ans.clear();
                ans.pb(0);
                ans.pb(x);
                ans.pb(pr[v]);
                ans.pb(v);
                ans.pb(x);
                ans.pb(n - 1);
                printans();
                return 0;
            }
        }

        auto ed = findNonEdge(comp, comp);
        //cerr << ed.first << ' ' << ed.second <<'\n';
        if (ed.first != -1) {
            ans.pb(0);
            ans.pb(ed.first);
            ans.pb(x);
            ans.pb(ed.second);
            ans.pb(ed.first);
            ans.pb(n - 1);
            printans();
            return 0;
        }
    }
    cout << -1 << '\n';
    
    return 0;
}