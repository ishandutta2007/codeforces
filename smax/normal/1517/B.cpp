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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> b(n, vector<int>(m));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin >> b[i][j];

        vector<int> mn(m, INT_MAX);
        vector<vector<int>> ret(n, vector<int>(m, -1));
        for (int i=0; i<n; i++) {
            sort(b[i].begin(), b[i].end());
            for (int j=0; j<m; j++) {
                pair<int, int> best(INT_MIN, -1);
                for (int k=0; k<m; k++)
                    if (ret[i][k] == -1)
                        best = max(best, {mn[k] - b[i][j], k});
                assert(best.second != -1);
                mn[best.second] = min(mn[best.second], b[i][j]);
                ret[i][best.second] = b[i][j];
            }
            for (int j=0; j<m; j++)
                cout << ret[i][j] << " ";
            cout << "\n";
        }
    }

    return 0;
}