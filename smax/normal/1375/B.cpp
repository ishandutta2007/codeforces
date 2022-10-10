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

int a[300][300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool ok = true;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                cin >> a[i][j];
                if ((i == 0 || i == n - 1) && (j == 0 || j == m - 1)) ok &= (a[i][j] <= 2), a[i][j] = 2;
                else if (i == 0 || i == n - 1 || j == 0 || j == m - 1) ok &= (a[i][j] <= 3), a[i][j] = 3;
                else ok &= (a[i][j] <= 4), a[i][j] = 4;
            }
        cout << (ok ? "YES" : "NO") << "\n";
        if (ok)
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    cout << a[i][j] << " \n"[j==m-1];
    }

    return 0;
}