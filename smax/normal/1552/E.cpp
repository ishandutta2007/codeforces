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

    int n, k;
    cin >> n >> k;
    vector<int> c(n * k), last(n, -1);
    vector<array<int, 3>> intervals;
    for (int i=0; i<n*k; i++) {
        cin >> c[i];
        c[i]--;
        if (last[c[i]] != -1)
            intervals.push_back({i, last[c[i]], c[i]});
        last[c[i]] = i;
    }

    sort(intervals.begin(), intervals.end());
    vector<bool> vis(n);
    vector<pair<int, int>> ret(n, {-1, -1});
    multiset<int> st;
    for (auto [r, l, x] : intervals)
        if (!vis[x]) {
            auto it = st.lower_bound(l);
            if (it == st.begin()) {
                if ((int) st.size() < (n + k - 2) / (k - 1)) {
                    vis[x] = true;
                    ret[x] = {l, r};
                    st.insert(r);
                }
            } else {
                vis[x] = true;
                ret[x] = {l, r};
                st.erase(prev(it));
                st.insert(r);
            }
        }

    for (auto [x, y] : ret) {
        assert(x != -1);
        cout << x + 1 << " " << y + 1 << "\n";
    }

    return 0;
}