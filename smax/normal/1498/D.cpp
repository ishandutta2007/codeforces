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

const long long MAX = 1e5;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, INF), ndp(m + 1), ret(m + 1, -1);
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        int t, y;
        long long x;
        cin >> t >> x >> y;
        fill(ndp.begin(), ndp.end(), INF);
        for (int j=0; j<=m; j++) {
            if (dp[j] != INF)
                ndp[j] = 0;
            if (ndp[j] < y) {
                long long nxt = t == 1 ? (j * MAX + x + MAX - 1) / MAX : (j * x + MAX - 1) / MAX;
                if (nxt <= m)
                    ndp[nxt] = min(ndp[nxt], ndp[j] + 1);
            }
            if (ndp[j] <= y && ret[j] == -1)
                ret[j] = i;
        }
        dp.swap(ndp);
    }
    for (int i=1; i<=m; i++)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}