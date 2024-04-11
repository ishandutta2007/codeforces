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
        int m, k;
        cin >> m >> k;
        priority_queue<pair<int, int>> pq;
        for (int i=1; i<=k; i++) {
            int a;
            cin >> a;
            if (a > 0) pq.emplace(a, i);
        }

        int n = 1;
        while (n * n - (n / 2) * (n / 2) < m)
            n++;

        vector<vector<int>> b;

        auto query = [&] (int r, int c) -> int {
            if (r < 0 || r >= n || c < 0 || c >= n) return 0;
            return b[r][c];
        };

        auto old = pq;
        while (true) {
            b = vector<vector<int>>(n, vector<int>(n));
            for (int d=1; d<=2*n-2; d+=2) {
                int l = max(d - n + 1, 0), r = min(d, n - 1);
                for (int i=l; i<=r; i++) {
                    int j = d - i;
                    if (!pq.empty()) {
                        auto [c, x] = pq.top();
                        pq.pop();
                        if (x == query(i - 1, j - 1) || x == query(i - 1, j + 1)) {
                            if (!pq.empty()) {
                                auto [d, y] = pq.top();
                                pq.pop();
                                if (y == query(i - 1, j - 1) || y == query(i - 1, j + 1)) {
                                    if (!pq.empty()) {
                                        auto [e, z] = pq.top();
                                        pq.pop();
                                        assert(z != query(i - 1, j - 1) && z != query(i - 1, j + 1));
                                        b[i][j] = z;
                                        e--;
                                        if (e > 0) pq.emplace(e, z);
                                    }
                                } else {
                                    b[i][j] = y;
                                    d--;
                                }
                                if (d > 0) pq.emplace(d, y);
                            }
                        } else {
                            b[i][j] = x;
                            c--;
                        }
                        if (c > 0) pq.emplace(c, x);
                    }
                }
            }
            for (int d=0; d<=2*n-2; d+=2) {
                int l = max(d - n + 1, 0), r = min(d, n - 1);
                for (int i=l; i<=r; i++) {
                    int j = d - i;
                    if ((i % 2 == 0 || j % 2 == 0) && !pq.empty()) {
                        auto [c, x] = pq.top();
                        pq.pop();
                        b[i][j] = x;
                        if (--c > 0) pq.emplace(c, x);
                    }
                }
            }
            if (pq.empty()) {
                cout << n << "\n";
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++)
                        cout << b[i][j] << " ";
                    cout << "\n";
                }
                break;
            }
            n++;
            pq = old;
        }
    }

    return 0;
}