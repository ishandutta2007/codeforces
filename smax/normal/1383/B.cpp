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

int a[100000];

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

        int tot = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            tot ^= a[i];
        }
        if (tot == 0) {
            cout << "DRAW\n";
            continue;
        }

        int j = 29;
        while (!(tot & (1 << j)))
            j--;
        int n0 = 0, n1 = 0;
        for (int i=0; i<n; i++) {
            if (a[i] & (1 << j))
                n1++;
            else
                n0++;
        }
        if (n0 % 2 == 0 && n1 % 4 == 3)
            cout << "LOSE\n";
        else
            cout << "WIN\n";
    }

    return 0;
}