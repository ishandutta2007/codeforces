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
        vector<vector<int>> a(n, vector<int>(m));
        vector<int> mx(m);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                cin >> a[i][j];
                mx[j] = max(mx[j], a[i][j]);
            }

        vector<int> perm(m);
        iota(perm.begin(), perm.end(), 0);
        sort(perm.begin(), perm.end(), [&] (int i, int j) -> bool {
            return tie(mx[i], i) > tie(mx[j], j);
        });
        perm.resize(min(m, n));

        vector<int> dp(1 << n), ndp(1 << n);
        for (int j : perm) {
            fill(ndp.begin(), ndp.end(), 0);
            for (int rot=0; rot<n; rot++) {
                vector<int> cur = dp;
                for (int i=0; i<n; i++) {
                    vector<int> ncur = cur;
                    for (int mask=0; mask<1<<n; mask++)
                        if (~mask & (1 << i))
                            ncur[mask | (1 << i)] = max(ncur[mask | (1 << i)], cur[mask] + a[(i + rot) % n][j]);
                    cur.swap(ncur);
                }
                for (int mask=0; mask<1<<n; mask++)
                    ndp[mask] = max(ndp[mask], cur[mask]);
            }
            dp.swap(ndp);
        }
        cout << dp[(1 << n) - 1] << "\n";
    }

    return 0;
}