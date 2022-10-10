#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

bool grid[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            for (int j=0; j<m; j++)
                grid[i][j] = s[j] == '1';
        }

        vector<vector<int>> ret;
        for (int i=0; i<n-2; i++) {
            for (int j=0; j<m-2; j++) {
                // fix top left corner
                if (grid[i][j]) {
                    ret.push_back({i, j, i, j + 1, i + 1, j + 1});
                    grid[i][j] ^= 1;
                    grid[i][j + 1] ^= 1;
                    grid[i + 1][j + 1] ^= 1;
                }
            }
            // fix top two cells
            vector<pair<int, int>> v;
            if (grid[i][m - 2])
                v.emplace_back(i, m - 2);
            if (grid[i][m - 1])
                v.emplace_back(i, m - 1);
            if (!v.empty()) {
                if (v.size() < 3)
                    v.emplace_back(i + 1, m - 2);
                if (v.size() < 3)
                    v.emplace_back(i + 1, m - 1);
                ret.emplace_back();
                for (auto [r, c] : v) {
                    grid[r][c] ^= 1;
                    ret.back().push_back(r);
                    ret.back().push_back(c);
                }
            }
        }
        for (int j=0; j<m-2; j++) {
            // fix left two cells
            vector<pair<int, int>> v;
            if (grid[n - 2][j])
                v.emplace_back(n - 2, j);
            if (grid[n - 1][j])
                v.emplace_back(n - 1, j);
            if (!v.empty()) {
                if (v.size() < 3)
                    v.emplace_back(n - 2, j + 1);
                if (v.size() < 3)
                    v.emplace_back(n - 1, j + 1);
                ret.emplace_back();
                for (auto [r, c] : v) {
                    grid[r][c] ^= 1;
                    ret.back().push_back(r);
                    ret.back().push_back(c);
                }
            }
        }

        // fix final square
        {
            vector<pair<int, int>> v, w;
            for (int i=n-2; i<n; i++)
                for (int j=m-2; j<m; j++) {
                    if (grid[i][j])
                        v.emplace_back(i, j);
                    else
                        w.emplace_back(i, j);
                }
            if ((int) v.size() == 1) {
                ret.push_back({v[0].first, v[0].second, w[0].first, w[0].second, w[1].first, w[1].second});
                ret.push_back({v[0].first, v[0].second, w[0].first, w[0].second, w[2].first, w[2].second});
                ret.push_back({v[0].first, v[0].second, w[1].first, w[1].second, w[2].first, w[2].second});
            } else if ((int) v.size() == 2) {
                ret.push_back({v[0].first, v[0].second, w[0].first, w[0].second, w[1].first, w[1].second});
                ret.push_back({v[1].first, v[1].second, w[0].first, w[0].second, w[1].first, w[1].second});
            } else if ((int) v.size() == 3) {
                ret.emplace_back();
                for (auto [r, c] : v) {
                    grid[r][c] ^= 1;
                    ret.back().push_back(r);
                    ret.back().push_back(c);
                }
            } else if ((int) v.size() == 4) {
                ret.push_back({v[0].first, v[0].second, v[1].first, v[1].second, v[2].first, v[2].second});
                ret.push_back({v[3].first, v[3].second, v[1].first, v[1].second, v[2].first, v[2].second});
                ret.push_back({v[3].first, v[3].second, v[1].first, v[1].second, v[0].first, v[0].second});
                ret.push_back({v[3].first, v[3].second, v[0].first, v[0].second, v[2].first, v[2].second});
            }
        }

        assert((int) ret.size() <= n * m);
        cout << ret.size() << "\n";
        for (auto &v : ret) {
            for (int i=0; i<6; i++)
                cout << v[i] + 1 << " ";
            cout << "\n";
        }
    }

    return 0;
}