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

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<vector<int>> cnt(m);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        cnt[a[i] % m].push_back(i);
    }
    int amt = n / m;

    vector<int> pref(m);
    for (int i=0; i<m; i++)
        pref[i] = (i > 0 ? pref[i-1] : 0) + max((int) cnt[i].size() - amt, 0) - max(amt - (int) cnt[i].size(), 0);

    int pos = int(min_element(pref.begin(), pref.end()) - pref.begin()) + 1;
    if (pos == m)
        pos = 0;
    vector<int> group;
    vector<pair<int, int>> ops;
    int i = pos;
    while (true) {
        if ((int) cnt[i].size() < amt) {
            assert(group.size() >= amt - cnt[i].size());
            for (int j=0; j<amt-(int)cnt[i].size(); j++) {
                ops.emplace_back(group.back(), i);
                group.pop_back();
            }
        } else if ((int) cnt[i].size() > amt) {
            for (int j=amt; j<(int)cnt[i].size(); j++)
                group.push_back(cnt[i][j]);
        }
        i = (i + 1) % m;
        if (i == pos)
            break;
    }

    long long ret = 0;
    for (auto [x, y] : ops) {
        int rem = a[x] % m;
        if (y >= rem) a[x] += y - rem, ret += y - rem;
        else a[x] += y + m - rem, ret += y + m - rem;
    }

    cout << ret << "\n";
    for (long long x : a)
        cout << x << " ";
    cout << "\n";

    return 0;
}