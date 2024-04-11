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

    int n, m;
    cin >> n >> m;
    int row = 0, col = 0;
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        row ^= a[i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
        col ^= b[i];
    }

    if (row != col) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<int>> ret(n, vector<int>(m));
    int cur = 0;
    for (int j=0; j<m-1; j++) {
        ret[0][j] = b[j];
        cur ^= b[j];
    }
    ret[0][m-1] = a[0] ^ cur;
    cur = ret[0][0];
    for (int i=1; i<n-1; i++) {
        ret[i][0] = a[i];
        cur ^= a[i];
    }
    ret[n-1][0] = b[0] ^ cur;
    ret[n-1][m-1] = b[m-1] ^ ret[0][m-1];
    assert((ret[n-1][0] ^ ret[n-1][m-1]) == a[n-1]);

    cout << "YES\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cout << ret[i][j] << " ";
        cout << "\n";
    }

    return 0;
}