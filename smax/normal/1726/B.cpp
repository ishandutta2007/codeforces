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
        int n, m;
        cin >> n >> m;

        if (n % 2) {
            if (m < n) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
                for (int i=0; i<n-1; i++)
                    cout << "1 ";
                cout << m - n + 1 << "\n";
            }
        } else {
            if (n == 2) {
                if (m % 2 == 0)
                    cout << "Yes\n" << m / 2 << " " << m / 2 << "\n";
                else
                    cout << "No\n";
            } else {
                if (m % n == 0) {
                    cout << "Yes\n";
                    for (int i=0; i<n; i++)
                        cout << m / n << " ";
                    cout << "\n";
                    continue;
                }
                if (m == n) {
                    cout << "Yes\n";
                    for (int i=0; i<n; i++)
                        cout << m / n << " ";
                    cout << "\n";
                } else if (m == n + 1) {
                    cout << "No\n";
                } else if (m == n + 2) {
                    cout << "Yes\n";
                    for (int i=0; i<n-2; i++)
                        cout << "1 ";
                    cout << "2 2\n";
                } else if (m > n + 2) {
                    // cout << "Yes\n";
                    // for (int i=0; i<n-3; i++)
                    //     cout << "1 ";
                    // cout << "2 3 " <<
                    if (m % 2 == 0) {
                        cout << "Yes\n";
                        for (int i=0; i<n-2; i++)
                            cout << "1 ";
                        cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << "\n";
                    } else {
                        cout << "No\n";
                    }
                } else {
                    cout << "No\n";
                }
            }
        }
    }

    return 0;
}