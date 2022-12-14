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

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i=0; i<n; i++)
        cin >> grid[i];

    int ret = 0;
    for (int i=0; i<n; i++) {
        vector<string> old = grid;
        for (int j=0; j<n; j++)
            if (grid[i][j] == '0')
                for (int k=0; k<n; k++)
                    grid[k][j] = grid[k][j] == '1' ? '0' : '1';
        int cur = 0;
        for (int k=0; k<n; k++) {
            bool ok = true;
            for (int j=0; j<n; j++)
                ok &= grid[k][j] == '1';
            if (ok) cur++;
        }
        ret = max(ret, cur);
    }
    cout << ret << "\n";

    return 0;
}