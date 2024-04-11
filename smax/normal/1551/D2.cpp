#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int extraHori = 0, extraVert = 0;
        if (n % 2) extraHori = m / 2;
        else if (m % 2) extraVert = n / 2;
        DEBUG(extraHori, extraVert);
        if (extraHori > k) {
            cout << "NO\n";
            continue;
        }
        k -= extraHori;

        if (k <= n * m / 2 - extraHori - extraVert && k % 2 == 0) {
            cout << "YES\n";
            vector<string> grid(n, string(m, '?'));
            if (n % 2) {
                char c = 'a';
                for (int j=0; j<m; j+=2) {
                    grid[n-1][j] = grid[n-1][j+1] = c;
                    c = c == 'a' ? 'b' : 'a';
                }
            } else if (m % 2) {
                char c = 'a';
                for (int i=0; i<n; i+=2) {
                    grid[i][m-1] = grid[i+1][m-1] = c;
                    c = c == 'a' ? 'b' : 'a';
                }
            }
            for (int i=0; i+1<n; i+=2)
                for (int j=0; j+1<m; j+=2) {
                    if (k > 0) {
                        grid[i][j] = grid[i][j+1] = (i / 2 + j / 2) % 2 ? 'e' : 'c';
                        grid[i+1][j] = grid[i+1][j+1] = (i / 2 + j / 2) % 2 ? 'f' : 'd';
                        k -= 2;
                    } else {
                        grid[i][j] = grid[i+1][j] = (i / 2 + j / 2) % 2 ? 'e' : 'c';
                        grid[i][j+1] = grid[i+1][j+1] = (i / 2 + j / 2) % 2 ? 'f' : 'd';
                    }
                }
            for (const string &s : grid)
                cout << s << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}