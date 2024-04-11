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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), row(n, vector<int>(m)), col(m, vector<int>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            row[i][j] = a[i][j];
            col[j][i] = a[i][j];
        }

    for (int i=0; i<n; i++) {
        sort(row[i].begin(), row[i].end());
        row[i].erase(unique(row[i].begin(), row[i].end()), row[i].end());
    }
    for (int i=0; i<m; i++) {
        sort(col[i].begin(), col[i].end());
        col[i].erase(unique(col[i].begin(), col[i].end()), col[i].end());
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x = lower_bound(row[i].begin(), row[i].end(), a[i][j]) - row[i].begin();
            int y = lower_bound(col[j].begin(), col[j].end(), a[i][j]) - col[j].begin();
            cout << max((int) row[i].size() - x, (int) col[j].size() - y) + max(x, y) << " ";
        }
        cout << "\n";
    }

    return 0;
}