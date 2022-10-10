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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n);
        for (int i=0; i<n; i++)
            cin >> x[i];
        vector<string> s(n);
        for (int i=0; i<n; i++)
            cin >> s[i];

        long long mx = LLONG_MIN;
        vector<int> best;
        for (int mask=0; mask<1<<n; mask++) {
            vector<int> coef(m);
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (s[i][j] == '1')
                        coef[j] += mask >> i & 1 ? -1 : 1;
            vector<int> order(m);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&] (int i, int j) -> bool {
                return coef[i] < coef[j];
            });
            long long cur = 0;
            for (int i=0; i<n; i++)
                cur += mask >> i & 1 ? x[i] : -x[i];
            for (int i=0; i<m; i++)
                cur += coef[order[i]] * (i + 1);
            if (cur > mx) {
                mx = cur;
                best = order;
            }
        }

        vector<int> ret(m);
        for (int i=0; i<m; i++)
            ret[best[i]] = i + 1;
        for (int i=0; i<m; i++)
            cout << ret[i] << " ";
        cout << "\n";
    }

    return 0;
}