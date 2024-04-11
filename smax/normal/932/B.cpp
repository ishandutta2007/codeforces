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

#define MAX 1000005

int f(int n) {
    int ret = 1;
    while (n > 0) {
        if (n % 10) ret *= n % 10;
        n /= 10;
    }
    return ret;
}

int g[MAX], pref[MAX][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i=1; i<10; i++)
        g[i] = i;
    for (int i=10; i<MAX; i++)
        g[i] = g[f(i)];
    for (int i=1; i<MAX; i++)
        for (int j=1; j<10; j++)
            pref[i][j] = pref[i-1][j] + (g[i] == j);

    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << pref[r][k] - pref[l-1][k] << "\n";
    }

    return 0;
}