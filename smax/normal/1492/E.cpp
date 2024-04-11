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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    auto solve = [&] (auto &self, int ops) -> bool {
        for (int i=1; i<n; i++) {
            vector<int> diff;
            for (int j=0; j<m; j++)
                if (a[0][j] != a[i][j])
                    diff.push_back(j);
            int d = (int) diff.size();
            if (d > ops + 2)
                return false;
            if (d > 2) {
                for (int mask=1; mask<1<<d; mask++)
                    if (__builtin_popcount(mask) == d - 2) {
                        vector<pair<int, int>> memo;
                        for (int j=0; j<d; j++)
                            if (mask & (1 << j)) {
                                memo.emplace_back(diff[j], a[0][diff[j]]);
                                a[0][diff[j]] = a[i][diff[j]];
                            }
                        if (self(self, ops - d + 2))
                            return true;
                        for (auto [j, x] : memo)
                            a[0][j] = x;
                    }
                return false;
            }
        }
        return true;
    };

    if (solve(solve, 2)) {
        cout << "Yes\n";
        for (int j=0; j<m; j++)
            cout << a[0][j] << " ";
        cout << "\n";
    } else {
        cout << "No\n";
    }

    return 0;
}