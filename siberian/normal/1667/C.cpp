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


bool check(int n, const vector<vector<int>>& used) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!used[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void print(int n, int ans, vector<vector<int>>& used) {
    cout << "n = " << n << " ans = " << ans << endl;
    assert(ans == n - (n + 1) / 3);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            cout << used[x][y];
        }
        cout << endl;
    }
    cout << endl;
    assert(check(n, used));
}

bool checkCell(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void paint(int n, int x, int y, vector<vector<int>>& used) {
    used[x][y] = 2;
    for (int d = -n; d <= n; ++d) {
        int nx, ny;
        nx = x + d;
        ny = y;
        if (checkCell(nx, ny, n) && !used[nx][ny]) {
            used[nx][ny] = 1;
        }
        nx = x;
        ny = y + d;
        if (checkCell(nx, ny, n) && !used[nx][ny]) {
            used[nx][ny] = 1;
        }
        nx = x + d;
        ny = y + d;
        if (checkCell(nx, ny, n) && !used[nx][ny]) {
            used[nx][ny] = 1;
        }
    }
}

void brute(int n, int x, int y, int cur_ans, vector<vector<int>> used, int& min_ans, vector<vector<int>>& min_used) {
    if (cur_ans >= min_ans) {
        return;
    }
    if (x == n) {
        if (!check(n, used)) {
            return;
        }
        min_ans = cur_ans;
        min_used = used;
    } else {
        int ny = y + 1;
        int nx = x;
        if (ny == n) {
            ny = 0;
            nx = x + 1;
        }
        brute(n, nx, ny, cur_ans, used, min_ans, min_used);
        if (!used[x][y]) {
            if (x == 0 || x == n - 1 || y == 0 || y == n - 1 || abs(x + y - (n - 1)) <= 1 || abs(x + y - 2 * (n - 1)) <= 3) {
                ++cur_ans;
                paint(n, x, y, used);
                brute(n, x, y, cur_ans, used, min_ans, min_used);
            }
        }
    }
}

vector<pair<int, int>> get_diagonal(int n) {
    vector<pair<int, int>> ans;
    for (int x = 0; x < n; ++x) {
        ans.emplace_back(x, n - 1 - x);
    }
    return ans;
}

void smart(int n) {
    int del = (n + 1) / 3;
    vector<pair<int, int>> ans;
    {
        auto first = get_diagonal(del);
        for (auto [x, y] : first) {
            ans.emplace_back(x, y);
        }
    }
    {
        auto second = get_diagonal(del - 1);
        for (auto [x, y] : second) {
            ans.emplace_back(x + del, y + del);
        }
    }
    {
        auto other = get_diagonal(n - max(del, 0) - ans.size());
        int d = ans.size();
        for (auto [x, y] : other) {
            ans.emplace_back(x + d, y + d);
        }
    }
    // vector<vector<int>> used(n, vector<int>(n, 0));
    // for (auto [x, y] : ans) {
    //     paint(n, x, y, used);
    // }
    // print(n, ans.size(), used);
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    // for (int n = 1; n <= 1000; ++n) {
        // int min_ans = n + 1;
        // vector<vector<int>> used(n, vector<int>(n, 0));
        // auto min_used = used;
        // brute(n, 0, 0, 0, used, min_ans, min_used);
        // paint(n, 3, 3, min_used);
        // print(n, min_ans, min_used);
        // smart(n);
    // }
    int n;
    cin >> n;
    smart(n);
    return 0;
}