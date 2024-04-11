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

    int n, t;
    cin >> n >> t;
    vector<int> g(n), c(n);
    for (int i=0; i<n; i++)
        cin >> g[i] >> c[i];
    vector<long long> d(n);
    for (int i=1; i<n; i++)
        cin >> d[i];

    set<int> start;
    vector<pair<int, int>> intervals;
    for (int i=0; i<n; i++) {
        if (i > 0) d[i] += d[i-1];
        int l = ((g[i] - c[i] - d[i]) % t + t) % t, r = (l + t - g[i]) % t;
        start.insert((l + t - 1) % t);
        intervals.emplace_back(l, r);
    }

    set<pair<int, int>> st;
    map<int, int> mp;
    vector<int> nxt(n, -1);
    for (int x : start)
        st.emplace(x, -1);
    for (int i=0; i<n; i++) {
        auto [l, r] = intervals[i];
        auto it = st.lower_bound({l, -1});
        while (it != st.end() && it->first < (l < r ? r : t)) {
            if (it->second == -1)
                mp[it->first] = i;
            else
                nxt[it->second] = i;
            it = st.erase(it);
        }
        if (r < l) {
            it = st.lower_bound({r, -1});
            while (it != st.begin()) {
                it = prev(it);
                if (it->second == -1)
                    mp[it->first] = i;
                else
                    nxt[it->second] = i;
                it = st.erase(it);
            }
        }
        st.emplace(r, i);
    }

    vector<long long> ti(n);
    for (int i=n-1; i>=0; i--)
        if (nxt[i] != -1)
            ti[i] = ti[nxt[i]] + (intervals[nxt[i]].second - intervals[i].second + t) % t;

    long long ret = LLONG_MAX;
    for (int x : start)
        ret = min(ret, mp.count(x) ? ti[mp[x]] + (intervals[mp[x]].second - x + t) % t : 0);
    cout << ret + d[n-1] << "\n";

    return 0;
}