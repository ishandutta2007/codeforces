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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    if (k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO\n";
        return 0;
    }

    int row = 0;
    vector<pair<int, string>> ret;
    if (m == 1) {
        int f = min(n - 1, k);
        ret.emplace_back(f, "D");
        k -= f;
        if (k > 0)
            ret.emplace_back(k, "U");
    } else {
        while (k > 0 && row < n - 1) {
            int f = min(m - 1, k / 3);
            if (f == 0)
                break;
            ret.emplace_back(f, row % 2 ? "DUL" : "DUR");
            row++;
            k -= f * 3;
            if (k == 0)
                break;
            ret.emplace_back(1, "D");
            k--;
        }
        if (k > 0) {
            if (row < n - 1) {
                assert(k < 3);
                ret.emplace_back(1, "D");
                if (k == 2)
                    ret.emplace_back(1, "U");
            } else {
                int f = min(m - 1, k);
                ret.emplace_back(f, row % 2 ? "L" : "R");
                k -= f;
                if (k > 0) {
                    f = min(m - 1, k);
                    ret.emplace_back(f, row % 2 ? "R" : "L");
                    k -= f;
                    while (k > 0) {
                        ret.emplace_back(1, "U");
                        row--;
                        if (--k == 0)
                            break;
                        f = min(m - 1, k);
                        ret.emplace_back(f, row % 2 ? "R" : "L");
                        k -= f;
                    }
                }
            }
        }
    }

    cout << "YES\n" << ret.size() << "\n";
    for (auto p : ret)
        cout << p.first << " " << p.second << "\n";

    return 0;
}