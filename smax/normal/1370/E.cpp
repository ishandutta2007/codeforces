#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s, t;
    cin >> n >> s >> t;

    int n0 = 0, n1 = 0, cntS = 0, cntT = 0;
    for (int i=0; i<n; i++) {
        cntS += (s[i] == '1' ? 1 : -1);
        cntT += (t[i] == '1' ? 1 : -1);
        if (s[i] == '0' && t[i] == '1') {
            if (n1 > 0) n1--;
            n0++;
        } else if (s[i] == '1' && t[i] == '0') {
            if (n0 > 0) n0--;
            n1++;
        }
    }

    cout << (cntS == cntT ? n0 + n1 : -1) << "\n";

    return 0;
}