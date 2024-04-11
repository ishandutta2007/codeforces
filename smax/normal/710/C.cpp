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

int ret[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int odd = 1, even = 2;
    for (int i=0; i<n; i++) {
        ret[i][n / 2] = odd;
        odd += 2;
        if (i != n / 2) {
            ret[n / 2][i] = odd;
            odd += 2;
        }
    }
    for (int i=0; i<n/2; i++)
        for (int j=0; j<n/2; j++) {
            int &x = odd < n * n ? odd : even;
            ret[i][j] = x;
            x += 2;
            ret[i][n-j-1] = x;
            x += 2;
            ret[n-i-1][j] = x;
            x += 2;
            ret[n-i-1][n-j-1] = x;
            x += 2;
        }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << ret[i][j] << " ";
        cout << "\n";
    }

    return 0;
}