#include <algorithm>
#include <assert.h>
#include <chrono>
#include <functional>
#include <numeric>
#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <time.h>
#include <utility>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>

#include <bitset>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define countbits __builtin_popcountll
#define print(a)            cerr << (a) << '\n'
#define dbg(a)              cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)          cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c)       cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'
#define dbg4(a, b, c, d)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << '\n'
#define dbg5(a, b, c, d, e) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << " " << #e << " = " << (e) << '\n'
#define PI 3.1415926535897932384626433

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
using std::deque;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::max;
using std::min;

using std::sort;
using std::swap;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

void init() {
    std::iostream::sync_with_stdio(0);
    cout << std::fixed << std::setprecision(10);
    cerr << std::fixed << std::setprecision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

const int MAXN = 3003, INF = 1e9;
vector<int> graph[MAXN];
int dist[MAXN][MAXN];
bool used[MAXN];
int n, m;
void bfs(int s) {
    queue<int> q;
    q.push(s);
    for (int i = 1; i <= n; ++i) {
        dist[s][i] = INF;
        used[i] = false;
    }
    dist[s][s] = 0;
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to : graph[v]) {
            if (!used[to]) {
                used[to] = true;
                q.push(to);
                dist[s][to] = dist[s][v] + 1;
            }
        }
    }
}
int mx1[MAXN], mx2[MAXN], mx3[MAXN];
void fmx(int s) {
    int a = -1, b = -1, c = -1;
    for (int i = 1; i <= n; ++i) {
        if (i == s || dist[s][i] == INF) continue;
        a = i;
        break;
    }
    if (a != -1) {
        for (int i = a + 1; i <= n; ++i) {
            if (i == s || dist[s][i] == INF) continue;
            b = i;
            break;
        }
        if (b != -1) {
            for (int i = b + 1; i <= n; ++i) {
                if (i == s || dist[s][i] == INF) continue;
                c = i;
                break;
            }
            if (dist[s][a] < dist[s][b]) swap(a, b);
            if (c != -1) {
                if (dist[s][b] < dist[s][c]) swap(b, c);
                if (dist[s][a] < dist[s][b]) swap(a, b);
                if (dist[s][b] < dist[s][c]) swap(b, c);
                for (int i = max(a, max(b, c)) + 1; i <= n; ++i) {
                    if (i == s || dist[s][i] == INF) continue;
                    if (dist[s][i] > dist[s][c]) {
                        c = i;
                    }
                    if (dist[s][i] > dist[s][b]) {
                        c = b;
                        b = i;
                    }
                    if (dist[s][i] > dist[s][a]) {
                        b = a;
                        a = i;
                    }
                }
            }
        }
    }
    mx1[s] = a;
    mx2[s] = b;
    mx3[s] = c;
}

int ans[4][MAXN];
pii mxb[4][MAXN];

void fmxb(int s) {
    set<pair<int, pii>> top;
    for (int i = 1; i <= n; ++i) {
        if (i == s || dist[s][i] == INF) continue;
        if (s != mx1[i] && mx1[i] != -1) {
            top.insert({dist[s][i] + dist[i][mx1[i]], {i, mx1[i]}});
            if (top.size() > 4) top.erase(top.begin());
        }
        if (s != mx2[i] && mx2[i] != -1) {
            top.insert({dist[s][i] + dist[i][mx2[i]], {i, mx2[i]}});
            if (top.size() > 4) top.erase(top.begin());
        }
        if (s != mx3[i] && mx3[i] != -1) {
            top.insert({dist[s][i] + dist[i][mx3[i]], {i, mx3[i]}});
            if (top.size() > 4) top.erase(top.begin());
        }
    }
    vector<pair<int, pii>> q;
    for (auto i : top) q.pb(i);
    std::reverse(q.begin(), q.end());
    for (int i = 0; i < 4; ++i) ans[i][s] = -1; 
    for (int i = 0; i < min(4, int(q.size())); ++i) {
        ans[i][s] = q[i].ff;
        mxb[i][s] = q[i].ss;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
    }

    for (int i = 1; i <= n; ++i) 
        bfs(i);

    for (int i = 1; i <= n; ++i) 
        fmx(i);

    for (int i = 1; i <= n; ++i)
        fmxb(i);

    // for (int i = 1; i <= n; ++i) {
    //     for (int k = 0; k < 4; ++k)
    //         dbg5(i, k, mxb[k][i].ff, mxb[k][i].ss, dist[i][mxb[k][i].ff] + dist[mxb[k][i].ff][mxb[k][i].ss]);
    // }

    int nans = 0, na, nb, nc, nd;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            if (a == b || dist[a][b] == INF) continue;
            for (int k = 0; k < 4; ++k) {
                if (ans[k][b] == -1) continue;
                int c = mxb[k][b].ff, d = mxb[k][b].ss;
                if (a == c || a == d) continue;
                int pot = dist[a][b] + dist[b][c] + dist[c][d];
                if (pot > nans) {
                    nans = pot;
                    na = a;
                    nb = b;
                    nc = c;
                    nd = d;
                }
            }
        }
    }
    // dbg(nans);
    cout << na << ' ' << nb << ' ' << nc << ' ' << nd << '\n';

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}