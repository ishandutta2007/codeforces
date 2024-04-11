#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 4e5 + 10;
// const int N = 1000;
int n, m;
string a[N];
int need[N];

vector<int> g[N];
vector<int> rg[N];

int getV(int x, int y) {
    return x * m + y;
}

void addEdge(int from, int to) {
    g[from].push_back(to);
    rg[to].push_back(from);
    // cerr << " from = " << from << " to = " << to << endl;
    // cerr << from << " " << to << endl;
}

int last[N];

bool checkCell(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void buildG() {
    fill(last, last + m, -1);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '#') continue;
            for (int dy = -1; dy <= 1; ++dy) {
                int y = j + dy;
                if (y < 0 || y >= m) continue;
                if (last[y] == -1) continue;
                // cerr << "from = " << i << " " << j << " to = " << last[y] << " " << y << endl;
                addEdge(getV(i, j), getV(last[y], y));
            }
            last[j] = i;
        }
    }

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (a[x][y] != '#') continue;
            for (int it = 0; it < 4; ++it) {
                int nx = x + dx[it];
                int ny = y + dy[it];
                if (!checkCell(nx, ny)) continue;
                if (a[nx][ny] != '#') continue;
                addEdge(getV(x, y), getV(nx, ny));
            }
        }
    }
}

int order[N];
int topOrder = 0;
bool used[N];

void dfsOrder(int v) {
    used[v] = true;
    for (auto i : g[v]) {
        if (used[i]) continue;
        dfsOrder(i);
    }
    order[topOrder++] = v;
}

int color[N];

void dfsColor(int v, int c) {
    color[v] = c;
    for (auto i : rg[v]) {
        if (color[i] != -1) continue;
        dfsColor(i, c);
    }
}

bool hasEdge[N];
int c;

void buildSCC() {
    fill(used, used + N, false);
    for (int i = 0; i < n * m; ++i) {
        if (used[i]) continue;
        if (a[i / m][i % m] != '#') continue;
        dfsOrder(i);
    }
    fill(color, color + N, -1);
    reverse(order, order + topOrder);
    // cerr << "order = " << endl;
    // for (int i = 0; i < topOrder; ++i) {
    //     cerr << order[i] << ' ';
    // }
    // cerr << endl;
    c = 0;
    for (int i = 0; i < topOrder; ++i) {
        int v = order[i];
        if (color[v] != -1) continue;
        dfsColor(v, c++);
    }
}

int ans;

vector<int> ng[N];

void buildNg() {
    for (int from = 0; from < n * m; ++from) {
        for (auto to : g[from]) {
            if (color[from] == color[to]) continue;
            // ng[color[from]].push_back(color[to]);
            ng[color[to]].push_back(color[from]);
        }
    }
    for (int i = 0; i < c; ++i) {
        sort(all(ng[i]));
        ng[i].resize(unique(all(ng[i])) - ng[i].begin());
    }
}

// void calcAns() {
//     fill(hasEdge, hasEdge + N, false);
//     for (int i = 0; i < n * m; ++i) {
//         for (auto to : g[i]) {
//             if (color[i] == color[to]) continue;
//             hasEdge[color[to]] = true;
//         }
//     }
//     ans = 0;
//     for (int i = 0; i < c; ++i) {
//         if (!hasEdge[i]) {
//             ++ans;
//         }
//     }
// }

int dp[N];

int needY[N];

void calcDp() {
    fill(dp, dp + N, -1);
    for (int y = 0; y < m; ++y) {
        if (last[y] == -1) continue;
        int v = getV(last[y], y);
        int id = color[v];
        chkmax(dp[id], y);
    }
    for (int i = 0; i < c; ++i) {
        for (auto to : ng[i]) {
            assert(to < i);
            chkmax(dp[i], dp[to]);
        }
    }
}

vector<int> pos[N];

void buildNeed() {
    for (int y = 0; y < m; ++y) {
        for (int x = n - 1; x >= 0; --x) {
            if (a[x][y] == '#') {
                pos[y].push_back(x);
            }
        }
    }
}

int haveNeed[N];

void dfsSub(int v) {
    // cerr << "dfsSub: " << v / m << " " << v % m << endl;
    used[v] = true;
    need[v % m]--;
    haveNeed[v % m]++;
    chkmax(need[v % m], 0);
    for (auto i : g[v]) {
        if (used[i]) continue;
        dfsSub(i);
    }
}

void print() {
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (used[x * m + y]) {
                cerr << "0";
            } else {
                cerr << a[x][y];
            }
            cerr << " ";
        }
        cerr << endl;
    }
    for (int i = 0; i < m; ++i) {
        cerr << need[i] << ' ';
    }
    cerr << endl;
}

void calcAns() {
    fill(used, used + N, false);
    ans = 0;
    int ptr = 0;
    while (ptr < m) {
        while (ptr < m && need[ptr] == 0) ++ptr;
        if (ptr == m) break;
        int r = ptr;
        int maxY = m;
        while (r < m && r <= maxY) {
            int nxtY = m;
            if (need[r] > 0) {
                // cerr << "x = " << pos[r][need[r] + haveNeed[r] - 1] << " y = " << r << " ";
                nxtY = dp[color[getV(pos[r][need[r] + haveNeed[r] - 1], r)]];
                // cerr << "nxtY = " << nxtY << endl;
            }
            // cerr << "r = " << r << " nxtY = " << nxtY << endl;
            chkmin(maxY, nxtY);
            ++r;
        } 
        ++ans;
        // cerr << "ptr = " << ptr << " r = " << r << endl;
        ptr = r;
        // cerr << "r - 1 = " << r - 1 << endl;
        assert(!pos[r - 1].empty());
        dfsSub(pos[r - 1].back() * m + r - 1);
        // print();
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // for (int j = 0; j < m; ++j) {
        //     cerr << a[i][j] << ' ';
        // }
        // cerr << endl;
    }
    for (int i = 0; i < m; ++i) {
        cin >> need[i];
        // cerr << need[i] << " ";
    }
    // cerr << endl;
    buildG();
    buildSCC();
    // calcAns();
    // cout << ans << endl;
    buildNg();
    calcDp();
    buildNeed();
    calcAns();
    cout << ans << endl;
    return 0;
}