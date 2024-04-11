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

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        int n = a + b;

        for (char c : s) {
            if (c == '0') a--;
            else if (c == '1') b--;
        }
        bool ok = true;
        for (int i=0; i<n/2; i++) {
            if (s[i] == '?' && s[n-i-1] == '0') {
                s[i] = '0';
                a--;
            } else if (s[i] == '?' && s[n-i-1] == '1') {
                s[i] = '1';
                b--;
            } else if (s[i] == '0' && s[n-i-1] == '?') {
                s[n-i-1] = '0';
                a--;
            } else if (s[i] == '1' && s[n-i-1] == '?') {
                s[n-i-1] = '1';
                b--;
            } else if (s[i] != s[n-i-1]) {
                ok = false;
            }
        }
        DEBUG(a, b, s);
        if (a < 0 || b < 0 || !ok || ((n % 2 == 1 && s[n/2] == '?') && !((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0)))
        || ((n % 2 == 0 || s[n/2] != '?') && (a % 2 == 1 || b % 2 == 1))) {
            cout << "-1\n";
            continue;
        }

        if (n % 2 == 1 && s[n/2] == '?') {
            if (a % 2) {
                s[n/2] = '0';
                a--;
            } else {
                s[n/2] = '1';
                b--;
            }
        }
        for (int i=0; i<n/2; i++) {
            if (s[i] == '?') {
                assert(s[n-i-1] == '?');
                if (a > 0) {
                    s[i] = s[n-i-1] = '0';
                    a -= 2;
                } else {
                    s[i] = s[n-i-1] = '1';
                    b -= 2;
                }
            }
        }
        DEBUG(n, s, a, b);
        assert(a == 0 && b == 0);
        cout << s << "\n";
    }

    return 0;
}