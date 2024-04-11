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

long long power(long long a, long long b) {
    long long ret = 1;
    for (; b>0; b/=2) {
        if (b % 2) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin >> k;
    bool odd = true;
    long long pow2 = 2;
    for (int i=0; i<k; i++) {
        long long a;
        cin >> a;
        odd &= a % 2;
        pow2 = power(pow2, a);
    }
    pow2 = pow2 * power(2, MOD - 2) % MOD;

    if (odd)
        cout << (pow2 + MOD - 1) % MOD * power(3, MOD - 2) % MOD;
    else
        cout << (pow2 + 1) % MOD * power(3, MOD - 2) % MOD;
    cout << "/" << pow2 << "\n";

    return 0;
}