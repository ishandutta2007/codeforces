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

bool ok[50][50];
string grid[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> grid[i];

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                ok[i][j] = false;

        bool yes = true;
        for (int i=n-1; i>=0; i--)
            for (int j=n-1; j>=0; j--) {
                if (grid[i][j] == '0') continue;
                ok[i][j] = (i < n - 1 ? ok[i+1][j] : true);
                ok[i][j] |= (j < n - 1 ? ok[i][j+1] : true);
                if (!ok[i][j]) {
                    yes = false;
                    break;
                }
            }

        cout << (yes ? "YES" : "NO") << "\n";
    }

    return 0;
}