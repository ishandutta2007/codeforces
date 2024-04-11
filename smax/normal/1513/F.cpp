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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<tuple<int, int, int>> ev;
    long long sum = 0;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++) {
        cin >> b[i];
        sum += abs(a[i] - b[i]);
        ev.emplace_back(a[i], i, 0);
        ev.emplace_back(b[i], i, 1);
    }

    vector<set<pair<int, long long>>> inter(2), nested(2);
    vector<bool> vis(n);
    sort(ev.begin(), ev.end());
    long long ret = sum;
    for (auto [x, i, t] : ev) {
        if (vis[i]) {
            int y = t ? a[i] : b[i];
            auto it = inter[t ^ 1].lower_bound({y, LLONG_MAX});
            if (it != inter[t ^ 1].begin())
                ret = min(ret, sum - (x - y) + x + y + prev(it)->second);
            it = nested[t ^ 1].lower_bound({y, LLONG_MIN});
            if (it != nested[t ^ 1].end())
                ret = min(ret, sum - (x - y) + x - y + it->second);
            auto p = inter[t].emplace(y, -(x - y) - x - y);
            if (p.second) {
                it = p.first;
                if (it != inter[t].begin() && prev(it)->second <= it->second) {
                    inter[t].erase(it);
                } else {
                    while (next(it) != inter[t].end() && next(it)->second >= it->second)
                        inter[t].erase(next(it));
                }
            }
            p = nested[t].emplace(y, -(x - y) - x + y);
            if (p.second) {
                it = p.first;
                if (next(it) != nested[t].end() && next(it)->second <= it->second) {
                    nested[t].erase(it);
                } else {
                    while (it != nested[t].begin() && prev(it)->second >= it->second)
                        nested[t].erase(prev(it));
                }
            }
        } else {
            vis[i] = true;
        }
    }
    cout << ret << "\n";

    return 0;
}