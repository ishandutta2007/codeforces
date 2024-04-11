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

    int n, m;
    cin >> n >> m;
    vector<int> cnt(n), mn(n, INT_MAX);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a]++;
        mn[a] = min(mn[a], (b - a + n) % n);
    }

    for (int i=0; i<n; i++) {
        int ret = 0;
        for (int j=0; j<n; j++) {
            int p = (i + j) % n;
            if (cnt[p] > 0)
                ret = max(ret, j + n * (cnt[p] - 1) + mn[p]);
        }
        cout << ret << " ";
    }
    cout << "\n";

    return 0;
}