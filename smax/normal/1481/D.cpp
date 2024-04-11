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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        vector<vector<int>> cnt(n, vector<int>(2));
        for (int i=0; i<n; i++) {
            cin >> grid[i];
            for (int j=0; j<n; j++)
                if (i != j)
                    cnt[i][grid[i][j]-'a']++;
        }

        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if (grid[i][j] == grid[j][i]) {
                    // all same
                    cout << "YES\n";
                    for (int x=0; x<m+1; x++)
                        cout << (x % 2 ? i + 1 : j + 1) << " ";
                    cout << "\n";
                    goto done;
                }

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (i != j) {
                    if (m % 2) {
                        // ababa or babab
                        cout << "YES\n";
                        for (int x=0; x<m+1; x++)
                            cout << (x % 2 ? i + 1 : j + 1) << " ";
                        cout << "\n";
                        goto done;
                    } else {
                        // ab cycle, check if there exists an 'a' coming out of j
                        int val = grid[i][j] - 'a';
                        if (cnt[j][val] > 0) {
                            int k;
                            for (k=0; k<n; k++)
                                if (i != k && j != k && grid[j][k] - 'a' == val)
                                    break;
                            assert(k < n);
                            if (m % 4 == 0) {
                                // [baba] [abab]
                                cout << "YES\n" << j + 1 << " ";
                                for (int x=0; x<m/2; x++)
                                    cout << (x % 2 ? j + 1 : i + 1) << " ";
                                for (int x=0; x<m/2; x++)
                                    cout << (x % 2 ? j + 1 : k + 1) << " ";
                                cout << "\n";
                                goto done;
                            } else {
                                // [ababa] [ababa]
                                cout << "YES\n" << i + 1 << " ";
                                for (int x=0; x<m/2; x++)
                                    cout << (x % 2 ? i + 1 : j + 1) << " ";
                                for (int x=0; x<m/2; x++)
                                    cout << (x % 2 ? j + 1 : k + 1) << " ";
                                cout << "\n";
                                goto done;
                            }
                        }
                    }
                }
        cout << "NO\n";
        done:;
    }

    return 0;
}