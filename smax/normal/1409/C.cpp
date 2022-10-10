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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        // case 1: start with x
        int mn0 = INT_MAX, diff0 = -1;
        for (int i=1; i<n; i++)
            if ((y - x) % i == 0 && x + (y - x) / i * (n - 1) < mn0) {
                mn0 = x + (y - x) / i * (n - 1);
                diff0 = (y - x) / i;
            }
        // case 2: x is not first
        int mn1 = INT_MAX, diff1 = 0, first = -1;
        for (int i=1; i<n; i++)
            for (int j=1; j<x; j++)
                if ((x - j) % i == 0 && (y - j) % ((x - j) / i) == 0 && (y - j) / ((x - j) / i) <= n - 1 && j + (x - j) / i * (n - 1) < mn1) {
                    mn1 = j + (x - j) / i * (n - 1);
                    diff1 = (x - j) / i;
                    first = j;
                }
        if (mn0 < mn1) {
            cout << x;
            for (int i=1; i<n; i++)
                cout << " " << x + diff0 * i;
            cout << "\n";
        } else {
            cout << first;
            for (int i=1; i<n; i++)
                cout << " " << first + diff1 * i;
            cout << "\n";
        }
    }

    return 0;
}