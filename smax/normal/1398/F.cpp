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

int n, pref0[1000005], pref1[1000005], nxt[1000005];

bool ok(int i, int j) {
    return !((pref0[j] - (i > 0 ? pref0[i-1] : 0) > 0) && (pref1[j] - (i > 0 ? pref1[i-1] : 0) > 0));
}

int solve(int i, int len) {
    if (i + len - 1 >= n || ok(i, i + len - 1))
        return i;
    return nxt[i] = solve(nxt[i], len);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> n >> s;

    for (int i=0; i<n; i++) {
        pref0[i] = (i > 0 ? pref0[i-1] : 0) + (s[i] == '0');
        pref1[i] = (i > 0 ? pref1[i-1] : 0) + (s[i] == '1');
        nxt[i] = i + 1;
    }

    for (int len=1; len<=n; len++) {
        int ret = 0;
        for (int i=0; i<n; i+=len) {
            i = solve(i, len);
            ret += i + len - 1 < n && ok(i, i + len - 1);
        }
        cout << ret << " ";
    }
    cout << "\n";

    return 0;
}