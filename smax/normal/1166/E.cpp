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

    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(n);
    for (int i=0; i<m; i++) {
        int s;
        cin >> s;
        a[i].resize(s);
        for (int j=0; j<s; j++)
            cin >> a[i][j];
    }

    for (int i=0; i<m; i++)
        for (int j=i+1; j<m; j++) {
            vector<bool> has(n + 1);
            for (int x : a[i])
                has[x] = true;
            bool ok = false;
            for (int x : a[j])
                ok |= has[x];
            if (!ok) {
                cout << "impossible\n";
                return 0;
            }
        }
    cout << "possible\n";

    return 0;
}