#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

string grid[1000];
int up[1000][1000], down[1000][1000], lft[1000][1000], rght[1000][1000], prefV[1000][1000], prefH[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> grid[i];
        for (int j=0; j<m; j++) {
            up[i][j] = (grid[i][j] == '.' ? 0 : i > 0 ? up[i-1][j] + 1 : 1);
            lft[i][j] = (grid[i][j] == '.' ? 0 : j > 0 ? lft[i][j-1] + 1 : 1);
        }
    }

    for (int i=n-1; i>=0; i--)
        for (int j=m-1; j>=0; j--) {
            down[i][j] = (grid[i][j] == '.' ? 0 : i < n - 1 ? down[i+1][j] + 1 : 1);
            rght[i][j] = (grid[i][j] == '.' ? 0 : j < m - 1 ? rght[i][j+1] + 1 : 1);
        }

    vector<array<int, 3>> ret;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            int sz = min({up[i][j], down[i][j], lft[i][j], rght[i][j]}) - 1;
            DEBUG(i, j, sz)
            if (sz > 0) {
                ret.push_back({i + 1, j + 1, sz});
                prefV[i-sz][j]++;
                if (i + sz < n - 1)
                    prefV[i+sz+1][j]--;
                prefH[i][j-sz]++;
                if (j + sz < m - 1)
                    prefH[i][j+sz+1]--;
            }
        }

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (i > 0) prefV[i][j] += prefV[i-1][j];
            if (j > 0) prefH[i][j] += prefH[i][j-1];
            if (prefV[i][j] == 0 && prefH[i][j] == 0 && grid[i][j] == '*') {
                cout << "-1\n";
                return 0;
            }
        }

    cout << ret.size() << "\n";
    for (auto p : ret)
        cout << p[0] << " " << p[1] << " " << p[2] << "\n";

    return 0;
}