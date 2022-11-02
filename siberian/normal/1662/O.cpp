#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int R = 25;
const int A = 360;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

bool checkCell(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < A;
}

bool g[R][A][4];

void remove_edges_circular(int r, int a1, int a2) {
    for (int a = a1; a != a2; a = (a + 1) % A) {
        g[r - 1][a][1] = g[r][a][3] = false;
    }
}

void remove_edges_straight(int r1, int r2, int a) {
    for (int r = r1; r != r2; ++r) {
        g[r][(a - 1 + A) % A][0] = g[r][a][2] = false;
    }
}

void read() {
    for (int r = 0; r < R; ++r) {
        for (int a = 0; a < A; ++a) {
            for (int it = 0; it < 4; ++it) {
                g[r][a][it] = true;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;
        if (type == 'C') {
            int r, a1, a2;
            cin >> r >> a1 >> a2;
            remove_edges_circular(r, a1, a2);
        } else if (type == 'S') {
            int r1, r2, a;
            cin >> r1 >> r2 >> a;
            remove_edges_straight(r1, r2, a);
        } else {
            assert(false);
        }
    }
}

struct Pt{
    int r, a;
};

bool used[R][A];

bool bfs() {
    for (int r = 0; r < R; ++r) {
        for (int a = 0; a < A; ++a) {
            used[r][a] = 0;
        }
    }
    queue<Pt> q;
    for (int a = 0; a < A; ++a) {
        q.push({0, a});
        used[0][a] = true;
    }
    while (!q.empty()) {
        int r = q.front().r;
        int a = q.front().a;
        q.pop();
        for (int it = 0; it < 4; ++it) {
            if (!g[r][a][it]) continue;
            int nr = r + dx[it];
            int na = (a + dy[it] + A) % A;
            if (!checkCell(nr, na)) continue;
            if (used[nr][na]) continue;
            used[nr][na] = true;
            q.push({nr, na});
        }
    }
    for (int a = 0; a < A; ++a) {
        if (used[R - 1][a]) {
            return true;
        }
    }
    return false;
}

void solve() {
    read();
    if (bfs()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}