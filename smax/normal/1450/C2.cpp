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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k = 0;
        vector<string> grid(n);
        for (int i=0; i<n; i++) {
            cin >> grid[i];
            for (int j=0; j<n; j++)
                if (grid[i][j] != '.')
                    k++;
        }

        for (int d=0; d<3; d++)
            for (int e=0; e<3; e++)
                if (d != e) {
                    vector<string> old = grid;
                    int cnt = 0;
                    for (int i=0; i<n; i++)
                        for (int j=0; j<n; j++)
                            if (grid[i][j] != '.') {
                                if ((i + j) % 3 == d) {
                                    if (grid[i][j] == 'O')
                                        cnt++;
                                    grid[i][j] = 'X';
                                } else if ((i + j) % 3 == e) {
                                    if (grid[i][j] == 'X')
                                        cnt++;
                                    grid[i][j] = 'O';
                                }
                            }
                    if (cnt <= k / 3)
                        goto done;
                    grid = old;
                }
        assert(false);
        done:;

        for (int i=0; i<n; i++)
            cout << grid[i] << "\n";
    }

    return 0;
}