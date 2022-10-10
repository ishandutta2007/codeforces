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

    string s;
    int a, b;
    cin >> s >> a >> b;
    int n = (int) s.size();

    if (s[0] == '0') {
        cout << "NO\n";
        return 0;
    }

    vector<int> pw{1};
    for (int i=0; i<n; i++)
        pw.push_back(pw.back() * 10 % b);

    int l = 0, r = 0;
    for (char c : s)
        r = (r * 10 + int(c - '0')) % b;
    for (int i=0; i<n-1; i++) {
        l = (l * 10 + int(s[i] - '0')) % a;
        r = ((r - (long long) pw[n-i-1] * int(s[i] - '0')) % b + b) % b;
        if (s[i+1] != '0' && l == 0 && r == 0) {
            cout << "YES\n" << s.substr(0, i + 1) << "\n" << s.substr(i + 1) << "\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}