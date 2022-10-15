#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <utility>

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
#define dbg(a)        cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'

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
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
typedef pair<ushort, ushort> pus;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

void init() {
    std::iostream::sync_with_stdio(0);
    cout << std::fixed;
    cout.precision(10);
    cerr << std::fixed;
    cerr.precision(10);
    srand(time(0));
}

const int MAXN = 501;

vector<int> graph[MAXN];
bool used[MAXN];
char color[MAXN];
vector<int> vis;
bool bad = false;
int matr[MAXN][MAXN];
void dfs(int v, char c) {
    used[v] = true;
    vis.pb(v);
    color[v] = c;
    for (auto to : graph[v]) {
        if (color[to] != 'b' && color[to] != 0 && color[to] != c)
            bad = true;
        if (!used[to] && color[to] != 'b') {
            dfs(to, c);
        }
    }
}
int main() {
    init();


    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            matr[i][j] = 0;
    for (int i = 1; i <= m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
        matr[from][to] = matr[to][from] = 1;
    }
    int cntb = 0;
    for (int i = 1; i <= n; ++i) {
        matr[i][i] = 1;
        if (graph[i].size() == n - 1) {
            color[i] = 'b';
            ++cntb;
        }
    }

    char c = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && color[i] != 'b') {
            vis.clear();
            if (c == 'c') {
                cout<<"No\n";
                return 0;
            }
            if (c == 'a')
                c = 'c';
            if (c == 0)
                c = 'a';
            dfs(i, c);
            for (auto j : vis)
                for (auto k : vis)
                    if (!matr[j][k])
                        bad = true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!(color[i] >= 'a' && color[i] <= 'c')) bad = true; 
    }

    if (bad)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i)
        cout << color[i];
    cout << '\n';

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}