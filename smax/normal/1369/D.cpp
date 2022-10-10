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

const int MOD = 1e9 + 7;

long long ans[2000005], hasZero[2000005], hasOne[2000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ans[1] = 0;
    hasZero[1] = 1;
    hasOne[1] = 0;
    for (int i=2; i<=2000000; i++) {
        hasZero[i] = (2 * hasOne[i-1] + hasZero[i-1]) % MOD;
        hasOne[i] = hasZero[i-1];
        ans[i] = ((i - 3 >= 0 ? ans[i-3] : 0) + hasOne[i-1]) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] * 4 % MOD << "\n";
    }

    return 0;
}