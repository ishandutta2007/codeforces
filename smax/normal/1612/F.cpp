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

    int n, m, q;
    cin >> n >> m >> q;
    set<pair<int, int>> synergy;
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        synergy.emplace(a, b);
    }

    vector<pair<int, int>> que{{1, 1}};
    for (int d=0; ; d++) {
        vector<pair<int, int>> nque;
        for (auto [a, b] : que) {
            if (a == n && b == m) {
                cout << d << "\n";
                return 0;
            }
            int energy = a + b + (int) synergy.count({a, b});
            if (a < n)
                nque.emplace_back(min(energy, n), b);
            if (b < m)
                nque.emplace_back(a, min(energy, m));
        }
        sort(nque.rbegin(), nque.rend());
        vector<pair<int, int>> nque2;
        int mx = 0;
        for (auto [a, b] : nque) {
            if (b > mx) {
                nque2.emplace_back(a, b);
                mx = b;
            }
        }
        que.swap(nque2);
    }

    return 0;
}