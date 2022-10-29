#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

int n, m, q;
const int N = 300 * 1000 + 500;
int p[N];
int d[N];
int cnt[N];

void init() {
    forn (i, n) {
        p[i] = i;
        d[i] = 0;
        cnt[i] = 1;
    }
}

int leader(int v) {
    return p[v] == v ? v : p[v] = leader(p[v]);
}

void merge(int a, int b) {
    
    a = leader(a);
    b = leader(b);
    if (a == b)
        return;


    if (d[a] < d[b])
        swap(a, b);

    if (cnt[a] == 1) {
        if (d[a] == d[b]) {
            cnt[a] = 2;
            d[a]++;
        }
    } else {
        if (d[a] == d[b]) {
            cnt[a] = 2;
            d[a]++;
        } else {
            if (d[a] == d[b] + 1) {
                cnt[a] = 1;
            }
        }
    }

    p[b] = a;
}

vector<int> g[N];

bool read() {
    scanf("%d%d%d", &n, &m, &q);
    forn (i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    return false;
}

int dist[N];
int from[N];

void bfs(int v) {
    queue<int> q;
    vector<int> vx;
    
    forn (it, 2) {

        q.push(v);
        dist[v] = 0;
    
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (it == 0) vx.pb(v);
            forn (i, g[v].size()) {
                int to = g[v][i];
                if (dist[to] == INF) {
                    dist[to] = dist[v] + 1;
                    from[to] = v;
                    q.push(to);
                }
            }
        }

        v = vx[0];
        forn (i, vx.size()) {
            if (dist[vx[i]] > dist[v])
                v = vx[i];
        }
        if (it == 1)
            break;
        forn (i, vx.size())
            dist[vx[i]] = INF;
    }

    int to = vx[0];

    forn (i, vx.size()) {
        if (dist[to] < dist[vx[i]])
            to = vx[i];
    }

    int len = dist[to];

    forn (i, len / 2) {
        to = from[to];
    }
    
    if (len & 1)
        cnt[to]++;
    forn (i, vx.size())
        p[vx[i]] = to;
    d[to] = (len + 1) / 2;
}

int diametr(int a) {
    a = leader(a);
    if (cnt[a] == 1)
        return d[a] * 2;
    return d[a] * 2 - 1;
}

void solve() {
    init();

    forn (i, n)
        dist[i] = INF;

    forn (i, n) {
        if (dist[i] == INF)
            bfs(i);
    }

    forn (i, q) {
        int x, a;
        scanf("%d%d", &x, &a);
        a--;
        if (x == 1) {
            printf("%d\n", diametr(a));
        } else {
            int b;
            scanf("%d", &b);
            b--;
            merge(a, b);
        }
    }

}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    read();
    solve();

    return 0;
}