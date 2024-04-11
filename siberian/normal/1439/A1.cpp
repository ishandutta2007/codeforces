#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

struct Pt{
    int x, y;
};

const int N = 110;
int n, m;
char a[N][N];
vector<vector<Pt>> ans;

void inv(int x, int y) {
    a[x][y] = ((a[x][y] - '0') ^ 1) + '0';
}

void op(int x1, int y1, int x2, int y2, int x3, int y3) {
    ans.push_back({{x1, y1}, {x2, y2}, {x3, y3}});
    inv(x1, y1);
    inv(x2, y2);
    inv(x3, y3);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    ans.clear();

    for (int i = n - 1; i >= 2; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (a[i][j] == '0') continue;
            if (j == 0) {
                op(i, j, i - 1, j, i - 1, j + 1);
            } else {
                op(i, j, i - 1, j, i - 1, j - 1);
            }
        }
    }

    for (int j = m - 1; j >= 2; --j) {
        for (int i = 1; i >= 0; --i) {
            if (a[i][j] == '0') continue;
            op(i, j, 1, j - 1, 0, j - 1);
        }
    }

    for (int it = 0; it < 4; ++it) {
        vector<Pt> ops;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (a[i][j] == '0') continue;
                ops.push_back({i, j});
            }
        }
        int sz = ops.size();
        if (ops.empty()) break;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (a[i][j] == '1') continue;
                ops.push_back({i, j});
            }
        }
        if (sz == 1 || sz == 3) {
            ops.pop_back();
        } else {
            ops.erase(ops.begin());
        }
        op(ops[0].x, ops[0].y, ops[1].x, ops[1].y, ops[2].x, ops[2].y);
    }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        for (auto j : i) {
            cout << j.x + 1 << ' ' << j.y + 1 << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}