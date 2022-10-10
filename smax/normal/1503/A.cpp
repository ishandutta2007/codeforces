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
        int n;
        string s;
        cin >> n >> s;

        int k = (int) count(s.begin(), s.end(), '1');
        if (s[0] == '0' || s[n-1] == '0' || k % 2) {
            cout << "NO\n";
            continue;
        }

        int cnt0 = 0, cnt1 = 0;
        string a(n, '?'), b(n, '?');
        for (int i=0; i<n; i++) {
            if (s[i] == '1') {
                if (cnt1 < k / 2)
                    a[i] = b[i] = '(';
                else
                    a[i] = b[i] = ')';
                cnt1++;
            } else {
                if (cnt0 % 2) {
                    a[i] = '(';
                    b[i] = ')';
                } else {
                    a[i] = ')';
                    b[i] = '(';
                }
                cnt0++;
            }
        }
        cout << "YES\n" << a << "\n" << b << "\n";
    }

    return 0;
}