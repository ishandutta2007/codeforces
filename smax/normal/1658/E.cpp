#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> v;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            int a;
            cin >> a;
            v.push_back({a, i, j});
        }

    int sz = 0;
    vector<vector<int>> bit(2 * n + 1, vector<int>(2 * n + 1));

    auto _query = [&] (int x, int y) -> int {
        int ret = 0;
        for (int i=min(x+1, 2*n); i>0; i-=i&-i)
            for (int j=min(y+1, 2*n); j>0; j-=j&-j)
                ret += bit[i][j];
        return ret;
    };

    auto query = [&] (int x1, int y1, int x2, int y2) -> int {
        return _query(x2, y2) - _query(x2, y1 - 1) - _query(x1 - 1, y2) + _query(x1 - 1, y1 - 1);
    };

    auto update = [&] (int x, int y) -> void {
        sz++;
        for (int i=x+1; i<=2*n; i+=i&-i)
            for (int j=y+1; j<=2*n; j+=j&-j)
                bit[i][j]++;
    };

    sort(v.rbegin(), v.rend());
    vector<vector<bool>> ret(n, vector<bool>(n));
    for (auto [a, x, y] : v) {
        int i = x + y, j = x - y + n;
        if (sz - query(i - k, j - k, i + k, j + k) > 0)
            ret[x][y] = true;
        else
            update(i, j);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << (ret[i][j] ? 'G' : 'M');
        cout << "\n";
    }

    return 0;
}