#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

bool checkBad(int x, int y, int dx, int dy, int len, char need, vector<string>& a) {
    if (len == 0) return true;
    if (x < 0 || x >= a.size() || y < 0 || y >= a[0].size()) return false;
    if (a[x][y] != need) return false;
    return checkBad(x + dx, y + dy, dx, dy, len - 1, need, a);
}

//vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
//vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

bool checkBad(int x, int y, vector<string>& a) {
    if (a[x][y] == '.') return false;
    for (int it = 0; it < 4; ++it) {
        if (checkBad(x, y, dx[it], dy[it], 3, a[x][y], a)) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    int full = 0;
    for (auto i : a) {
        for (auto j : i) {
            full += j != '.';
        }
    }
    int cnt = 0;
    vector<vector<pair<int, int>>> fans(3);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){
            if (a[i][j] == '.') continue;
            if (a[i][j] == 'X') {
                fans[(i + j) % 3].push_back({i, j});
            } else if (a[i][j] == 'O') {
                fans[(i + j + 2) % 3].push_back({i, j});    
            }
        }
    }
    int mn = 0;
    for (int i = 0; i < 3; ++i) {
        if (fans[i].size() < fans[mn].size()){
            mn = i;
        }
    }
    for (auto i : fans[mn]) {
        ++cnt;
        if (a[i.first][i.second] == 'X') {
            a[i.first][i.second] = 'O';
        } else { 
            a[i.first][i.second] = 'X';
        }
    }
    assert(cnt * 3 <= full);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            assert(!checkBad(i, j, a));
        }
    }
    for (auto i : a) {
        cout << i << '\n';
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