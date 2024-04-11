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
        string s;
        cin >> n >> m >> s;

        long long cnt = count(s.begin(), s.end(), '1');
        if (cnt * m % n != 0) {
            cout << "-1\n";
            continue;
        }

        vector<int> pref(n + 1);
        for (int i=0; i<n; i++)
            pref[i+1] = pref[i] + (s[i] == '1');

        int ones = (int) (cnt * m / n);
        for (int i=m; i<=n; i++) {
            if (pref[i] - pref[i-m] == ones) {
                cout << "1\n" << i - m + 1 << " " << i << "\n";
                goto done;
            }
        }
        for (int i=1; i<m; i++)
            if (pref[i] + pref[n] - pref[n-(m-i)] == ones) {
                cout << "2\n1 " << i << "\n" << n - (m - i) + 1 << " " << n << "\n";
                goto done;
            }
        assert(false);
        done:;
    }

    return 0;
}