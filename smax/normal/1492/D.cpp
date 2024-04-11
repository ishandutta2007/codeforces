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

    int a, b, k;
    cin >> a >> b >> k;
    if (a == 0 || b == 1) {
        if (k == 0)
            cout << "Yes\n" << string(b, '1') << string(a, '0') << "\n" << string(b, '1') << string(a, '0') << "\n";
        else
            cout << "No\n";
    } else {
        if (k <= a + b - 2) {
            cout << "Yes\n" << string(b, '1') << string(a, '0') << "\n";
            if (k <= a)
                cout << string(b - 1, '1') << string(k, '0') << '1' << string(a - k, '0') << "\n";
            else
                cout << string(a + b - k - 1, '1') << '0' << string(k - a, '1') << string(a - 1, '0') << '1' << "\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}