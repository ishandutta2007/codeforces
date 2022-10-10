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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    int x = INF, y = INF;
    for (int i=1; i<n; i++) {
        if (a[i] > a[i-1]) {
            // right or down
            if (a[i] == a[i-1] + 1) {
                // right
            } else {
                // down
                if (y != INF && y != a[i] - a[i-1]) {
                    cout << "NO\n";
                    return 0;
                }
                y = a[i] - a[i-1];
            }
        } else if (a[i] < a[i-1]) {
            // left or up
            if (a[i] == a[i-1] - 1) {
                // left
            } else {
                // up
                if (y != INF && y != a[i-1] - a[i]) {
                    cout << "NO\n";
                    return 0;
                }
                y = a[i-1] - a[i];
            }
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    for (int i=1; i<n; i++) {
        if (a[i] == a[i-1] + 1) {
            int y1 = (a[i-1] - 1) % y, y2 = (a[i] - 1) % y;
            if (y2 != y1 + 1) {
                cout << "NO\n";
                return 0;
            }
        } else if (a[i] == a[i-1] - 1) {
            int y1 = (a[i-1] - 1) % y, y2 = (a[i] - 1) % y;
            if (y2 != y1 - 1) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n" << x << " " << y << "\n";

    return 0;
}