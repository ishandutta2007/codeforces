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
    // cin.tie(0);
    // std::iostream::sync_with_stdio(0);
    // cout << std::fixed << std::setprecision(10);
    // cerr << std::fixed << std::setprecision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

const int MAXN = 1002, TURN = 4, ALP = 256, CNT = 12, INF = 1e9;
const char ALL[CNT] = {'+','-','|','^','>','<','v','L','R','U','D','*'};
bool up[ALP], down[ALP], left[ALP], right[ALP];
char turn[TURN][ALP];

void fturn() {
    for (int i = 0; i < CNT; ++i) turn[0][ALL[i]] = ALL[i];
    turn[1]['+'] = '+';
    turn[1]['-'] = '|';
    turn[1]['|'] = '-';
    turn[1]['^'] = '>';
    turn[1]['>'] = 'v';
    turn[1]['v'] = '<';
    turn[1]['<'] = '^';
    turn[1]['L'] = 'U';
    turn[1]['U'] = 'R';
    turn[1]['R'] = 'D';
    turn[1]['D'] = 'L';
    turn[1]['*'] = '*';
    for (int i = 0; i < CNT; ++i) turn[2][ALL[i]] = turn[1][turn[1][ALL[i]]];
    for (int i = 0; i < CNT; ++i) turn[3][ALL[i]] = turn[1][turn[2][ALL[i]]];
}

void fup() {
    up['+'] = 1;
    up['-'] = 0;
    up['|'] = 1;
    up['^'] = 1;
    up['>'] = 0;
    up['v'] = 0;
    up['<'] = 0;
    up['L'] = 1;
    up['U'] = 0;
    up['R'] = 1;
    up['D'] = 1;
    up['*'] = 0;
}

void fdown() {
    down['+'] = 1;
    down['-'] = 0;
    down['|'] = 1;
    down['^'] = 0;
    down['>'] = 0;
    down['v'] = 1;
    down['<'] = 0;
    down['L'] = 1;
    down['U'] = 1;
    down['R'] = 1;
    down['D'] = 0;
    down['*'] = 0;
}

void fleft() {
    left['+'] = 1;
    left['-'] = 1;
    left['|'] = 0;
    left['^'] = 0;
    left['>'] = 0;
    left['v'] = 0;
    left['<'] = 1;
    left['L'] = 0;
    left['U'] = 1;
    left['R'] = 1;
    left['D'] = 1;
    left['*'] = 0;
}

void fright() {
    right['+'] = 1;
    right['-'] = 1;
    right['|'] = 0;
    right['^'] = 0;
    right['>'] = 1;
    right['v'] = 0;
    right['<'] = 0;
    right['L'] = 1;
    right['U'] = 1;
    right['R'] = 0;
    right['D'] = 1;
    right['*'] = 0;
}

char arr[MAXN][MAXN];

struct node{
    int t, x, y;
    node(int a, int b, int c): t(a), x(b), y(c) {}
};

int d[TURN][MAXN][MAXN];
bool used[TURN][MAXN][MAXN];

int main() {
    init();
    fturn();
    fup();
    fleft();
    fright();
    fdown();

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i <= n + 1; ++i) for (int j = 0; j <= m + 1; ++j) arr[i][j] = '*';

    // dbg2(n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf(" %c", &arr[i][j]);

    // for (int k = 0; k < TURN; ++k) {
    //     for (int i = 1; i <= n; ++i) { 
    //         for (int j = 1; j <= m; ++j) {
    //             char cur = turn[k][arr[i][j]];
    //             graph[k][i][j].pb(node((k + 1) % TURN, i, j));
    //             char attop = turn[k][arr[i - 1][j]], 
    //                  atleft = turn[k][arr[i][j - 1]], 
    //                  atright = turn[k][ arr[i][j + 1]], 
    //                  atdown = turn[k][arr[i + 1][j]];
    //             if (up[cur] && down[attop]) graph[k][i][j].pb(node(k, i - 1, j));
    //             if (down[cur] && up[atdown]) graph[k][i][j].pb(node(k, i + 1, j));
    //             if (left[cur] && right[atleft]) graph[k][i][j].pb(node(k, i, j - 1));
    //             if (right[cur] && left[atright]) graph[k][i][j].pb(node(k, i, j + 1));
    //         }
    //     }
    // }


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    for (int k = 0; k < TURN; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) 
                used[k][i][j] = 0;
    // print("ok");

    int mx, my, tx, ty;
    scanf("%d%d", &tx, &ty);
    scanf("%d%d", &mx, &my);
    // print("ok");
    // return 0;
    d[0][tx][ty] = 0;
    used[0][tx][ty] = 1;
    node s(0, tx, ty);
    queue<node> q;
    q.push(s);
    while (!q.empty()) {
        node v = q.front();
        int k = v.t, i = v.x, j = v.y;
        q.pop();
        {
            char cur = turn[k][arr[i][j]];
            {
                node to((k + 1) % TURN, i, j);
                int tot = to.t, tox = to.x, toy = to.y;
                if (!used[tot][tox][toy]) {
                    used[tot][tox][toy] = true;
                    q.push (to);
                    d[tot][tox][toy] = d[k][i][j] + 1;
                }
            }
            char attop = turn[k][arr[i - 1][j]], 
                 atleft = turn[k][arr[i][j - 1]], 
                 atright = turn[k][ arr[i][j + 1]], 
                 atdown = turn[k][arr[i + 1][j]];
            if (up[cur] && down[attop]) {
                node to(k, i - 1, j);
                int tot = to.t, tox = to.x, toy = to.y;
                if (!used[tot][tox][toy]) {
                    used[tot][tox][toy] = true;
                    q.push (to);
                    d[tot][tox][toy] = d[k][i][j] + 1;
                }
            }
            if (down[cur] && up[atdown]) {
                node to(k, i + 1, j);
                int tot = to.t, tox = to.x, toy = to.y;
                if (!used[tot][tox][toy]) {
                    used[tot][tox][toy] = true;
                    q.push (to);
                    d[tot][tox][toy] = d[k][i][j] + 1;
                }
            }
            if (left[cur] && right[atleft]) {
                node to(k, i, j - 1);
                int tot = to.t, tox = to.x, toy = to.y;
                if (!used[tot][tox][toy]) {
                    used[tot][tox][toy] = true;
                    q.push (to);
                    d[tot][tox][toy] = d[k][i][j] + 1;
                }
            }
            if (right[cur] && left[atright]) {
                node to(k, i, j + 1);
                int tot = to.t, tox = to.x, toy = to.y;
                if (!used[tot][tox][toy]) {
                    used[tot][tox][toy] = true;
                    q.push (to);
                    d[tot][tox][toy] = d[k][i][j] + 1;
                }
            }
        }
        // for (size_t i = 0; i < graph[t][x][y].size(); ++i) {
        //     node to = graph[t][x][y][i];
        //     int tot = to.t, tox = to.x, toy = to.y;
        //     if (!used[tot][tox][toy]) {
        //         used[tot][tox][toy] = true;
        //         q.push (to);
        //         d[tot][tox][toy] = d[t][x][y] + 1;
        //     }
        // }
    }

    int ans = INF;
    for (int i = 0; i < TURN; ++i) {
        if (used[i][mx][my])
            ans = min(ans, d[i][mx][my]);
    }

    if (ans == INF) ans = -1;

    printf("%d", ans);

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}