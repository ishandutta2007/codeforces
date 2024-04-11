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

int pref[1000000];
bool hasNeg[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    for (int i=0; i<n; i++) {
        pref[i] = (i > 0 ? pref[i-1] : 0) + (s[i] == '(' ? 1 : -1);
        hasNeg[i] = (i > 0 ? hasNeg[i-1] : false) || (pref[i] < 0);
    }

    int mn = INT_MAX, ret = 0;
    for (int i=n-1; i>=0; i--) {
        mn = min(mn, pref[i]);
        if (((s[i] == '(' && mn >= 2 && pref[n-1] == 2) || (s[i] == ')' && mn >= -2 && pref[n-1] == -2)) && (i == 0 || !hasNeg[i-1]))
            ret++;
    }

    cout << ret << "\n";

    return 0;
}