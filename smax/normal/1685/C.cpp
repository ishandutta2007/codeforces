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
        int n;
        string s;
        cin >> n >> s;

        int bal = 0, l = -1, r = -1, mx = 0, peak = -1;
        for (int i=0; i<2*n; i++) {
            bal += s[i] == '(' ? 1 : -1;
            if (bal < 0) {
                if (l == -1)
                    l = i;
                r = i;
            }
            if (bal > mx) {
                mx = bal;
                peak = i;
            }
        }
        if (l == -1) {
            cout << "0\n";
            continue;
        }

        int idxL = 0;
        mx = bal = 0;
        for (int i=0; i<l; i++) {
            bal += s[i] == '(' ? 1 : -1;
            if (bal > mx) {
                mx = bal;
                idxL = i + 1;
            }
        }

        int idxR = -1;
        mx = INT_MIN;
        for (int i=l; i<2*n; i++) {
            bal += s[i] == '(' ? 1 : -1;
            if (i >= r && bal > mx) {
                mx = bal;
                idxR = i;
            }
        }

        reverse(s.begin() + idxL, s.begin() + idxR + 1);
        bal = 0;
        bool ok = true;
        for (char c : s) {
            bal += c == '(' ? 1 : -1;
            if (bal < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "1\n" << idxL + 1 << " " << idxR + 1 << "\n";
            continue;
        }

        cout << "2\n1 " << peak + 1 << "\n" << peak + 2 << " " << 2 * n << "\n";
    }

    return 0;
}