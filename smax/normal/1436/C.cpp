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

const int MAX = 1005;
const int MOD = 1e9 + 7;

long long fact[MAX], inv[MAX];

long long inverse(long long a) {
    long long ret = 1;
    for (int b=MOD-2; b>0; b/=2) {
        if (b % 2) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

long long choose(int n, int k) {
    if (k < 0 || n < k) return 0;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

void preprocess() {
    fact[0] = inv[0] = 1;
    for (int i=1; i<MAX; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = inverse(fact[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preprocess();

    int n, x, pos;
    cin >> n >> x >> pos;

    int bigger = 0, smaller = 0, l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (m == pos) {
            l = m + 1;
        } else if (m < pos) {
            l = m + 1;
            smaller++;
        } else {
            r = m;
            bigger++;
        }
    }
    cout << choose(x - 1, smaller) * choose(n - x, bigger) % MOD * fact[smaller] % MOD * fact[bigger] % MOD * fact[n - smaller - bigger - 1] % MOD << "\n";

    return 0;
}