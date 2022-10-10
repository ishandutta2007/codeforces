#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        if (n % 2) {
            cout << "NO\n";
            continue;
        }
        int can = n / 2;
        for (char c : s)
            if (c == '(')
                can--;
        if (can < 0) {
            cout << "NO\n";
            continue;
        }

        int bal = 0;
        bool ok = true;
        for (char c : s) {
            if (c == '(')
                bal++;
            else if (c == ')')
                bal--;
            else if (can > 0) {
                bal++;
                can--;
            } else {
                bal--;
            }
            if (bal < 0) {
                ok = false;
                break;
            }
        }
        ok &= bal == 0;
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}