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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        if (n * a != m * b) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<int> column(m);
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i=0; i<n; i++)
            for (int j=0; j<a; j++) {
                grid[i][j] = 1;
                column[j]++;
            }

//        DEBUG(grid)
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++)
                if (column[j] > b && grid[i][j] == 1) {
//                    DEBUG(column[j], j)
                    bool canMove = false;
                    for (int k=j+1; k<m; k++)
                        if (grid[i][k] == 0 && column[k] < b) {
                            grid[i][k] = 1;
                            column[k]++;
                            canMove = true;
                            break;
                        }
                    if (canMove) {
                        grid[i][j] = 0;
                        column[j]--;
                    }
                }
//            DEBUG(grid)
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++)
                cout << grid[i][j];
            cout << "\n";
        }
    }

    return 0;
}