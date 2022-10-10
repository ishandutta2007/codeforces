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

int a[200][200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    // Case 1: first row all 0's
    string rowOps(n, '0'), colOps(m, '0');
    for (int j=0; j<m; j++)
        if (a[0][j]) {
            colOps[j] = '1';
            for (int i=0; i<n; i++)
                a[i][j] ^= 1;
        }
    bool ok = true;
    int tRow = -1;
    for (int i=1; i<n; i++) {
        int tot = accumulate(a[i], a[i] + m, 0);
        if (tot != 0 && tot != m) {
            if (tRow != -1) {
                ok = false;
                break;
            }
            tRow = i;
        }
    }
    if (ok) {
        if (tRow != -1) {
            bool flipped = false;
            for (int j=1; j<m; j++)
                if (a[tRow][j] != a[tRow][j-1]) {
                    if (flipped) {
                        ok = false;
                        break;
                    }
                    flipped = true;
                }
            if (ok) {
                for (int i=1; i<n; i++)
                    if ((i <= tRow && a[i][0]) || (i > tRow && !a[i][0]))
                        rowOps[i] = '1';
                cout << "YES\n" << rowOps << "\n" << colOps << "\n";
                return 0;
            }
        } else {
            for (int i=1; i<n; i++)
                if (a[i][0])
                    rowOps[i] = '1';
            cout << "YES\n" << rowOps << "\n" << colOps << "\n";
            return 0;
        }
    }
    for (int j=0; j<m; j++)
        if (colOps[j] == '1')
            for (int i=0; i<n; i++)
                a[i][j] ^= 1;

    // Case 2: last row all 1's
    rowOps.assign(n, '0');
    colOps.assign(m, '0');
    for (int j=0; j<m; j++)
        if (!a[n-1][j]) {
            colOps[j] = '1';
            for (int i=0; i<n; i++)
                a[i][j] ^= 1;
        }
    ok = true;
    tRow = -1;
    for (int i=0; i<n-1; i++) {
        int tot = accumulate(a[i], a[i] + m, 0);
        if (tot != 0 && tot != m) {
            if (tRow != -1) {
                ok = false;
                break;
            }
            tRow = i;
        }
    }
    if (ok) {
        if (tRow != -1) {
            bool flipped = false;
            for (int j=1; j<m; j++)
                if (a[tRow][j] != a[tRow][j-1]) {
                    if (flipped) {
                        ok = false;
                        break;
                    }
                    flipped = true;
                }
            if (ok) {
                for (int i=0; i<n-1; i++)
                    if ((i <= tRow && a[i][0]) || (i > tRow && !a[i][0]))
                        rowOps[i] = '1';
                cout << "YES\n" << rowOps << "\n" << colOps << "\n";
                return 0;
            }
        } else {
            for (int i=0; i<n-1; i++)
                if (a[i][0])
                    rowOps[i] = '1';
            cout << "YES\n" << rowOps << "\n" << colOps << "\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}