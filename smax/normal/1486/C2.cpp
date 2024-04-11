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

int q = 0;

int ask(int l, int r) {
    assert(q++ < 20);
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int x;
    cin >> x;
    return x - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int mx2 = ask(0, n - 1);
    if (mx2 > 0 && ask(0, mx2) == mx2) {
        // maximum is in left
        int l = 0, r = mx2;
        while (l < r) {
            int m = (l + r) / 2;
            if (ask(m, mx2) == mx2)
                l = m + 1;
            else
                r = m;
        }
        cout << "! " << l << endl;
    } else {
        // maximum is in right
        int l = mx2 + 1, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (ask(mx2, m) == mx2)
                r = m;
            else
                l = m + 1;
        }
        cout << "! " << l + 1 << endl;
    }

    return 0;
}