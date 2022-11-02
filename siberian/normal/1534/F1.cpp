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

void calcAns() {
    fill(hasEdge, hasEdge + N, false);
    for (int i = 0; i < n * m; ++i) {
        for (auto to : g[i]) {
            if (color[i] == color[to]) continue;
            hasEdge[color[to]] = true;
        }
    }
    ans = 0;
    for (int i = 0; i < c; ++i) {
        if (!hasEdge[i]) {
            ++ans;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> need[i];
    }
    buildG();
    buildSCC();
    calcAns();
    cout << ans << endl;
    return 0;
}