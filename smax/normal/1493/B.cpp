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

    vector<int> rev(100), digit{0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
    for (int x=0; x<100; x++) {
        int a = digit[x % 10], b = digit[x / 10];
        rev[x] = a == -1 || b == -1 ? -1 : 10 * a + b;
    }

    int t;
    cin >> t;
    while (t--) {
        int h, m;
        string s;
        cin >> h >> m >> s;
        int a = stoi(s.substr(0, s.find(':'))), b = stoi(s.substr(s.find(':') + 1));
        while (rev[a] == -1 || rev[b] == -1 || rev[a] >= m || rev[b] >= h) {
            DEBUG(a, b);
            if (++b == m) {
                b = 0;
                if (++a == h)
                    a = 0;
            }
        }
        DEBUG(a, b, rev[a], rev[b]);
        cout << setw(2) << setfill('0') << a << ":" << setw(2) << setfill('0') << b << "\n";
    }

    return 0;
}