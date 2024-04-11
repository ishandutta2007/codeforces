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

const int MOD = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int dp[200005], ndp[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, g;
    cin >> r >> g;

    int row = 1, tot = 0, prevSum = 1;
    dp[r] = 1;
    while (true) {
        for (int red=max(r-tot, 0); red<=r; red++) {
            int green = r + g - tot - red;
            if (green >= 0) {
                if (red >= row) add(ndp[red - row], dp[red]);
                if (green >= row) add(ndp[red], dp[red]);
            }
        }
        tot += row++;
        int sum = 0;
        for (int red=max(r-tot, 0); red<=r; red++) {
            int green = r + g - tot - red;
            if (green >= 0) {
                add(sum, ndp[red]);
                dp[red] = ndp[red];
                ndp[red] = 0;
            }
        }
        if (sum == 0) {
            cout << prevSum << "\n";
            return 0;
        }
        prevSum = sum;
    }

    return 0;
}