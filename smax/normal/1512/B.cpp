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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i=0; i<n; i++)
            cin >> grid[i];

        int ar = -1, ac = -1, br = -1, bc = -1;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j] == '*') {
                    if (ar == -1) {
                        ar = i;
                        ac = j;
                    } else {
                        br = i;
                        bc = j;
                    }
                }
        assert(br != -1);

        if (ar == br) {
            if (ar == 0)
                grid[ar+1][ac] = grid[ar+1][bc] = '*';
            else
                grid[ar-1][ac] = grid[ar-1][bc] = '*';
        } else if (ac == bc) {
            if (ac == 0)
                grid[ar][ac+1] = grid[br][ac+1] = '*';
            else
                grid[ar][ac-1] = grid[br][ac-1] = '*';
        } else {
            grid[ar][bc] = grid[br][ac] = '*';
        }
        for (auto &s : grid)
            cout << s << "\n";
    }

    return 0;
}