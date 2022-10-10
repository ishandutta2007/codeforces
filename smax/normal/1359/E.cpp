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

const int MAX = 5e5 + 5;
const int MOD = 998244353;

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

void preprocess(int n) {
    fact[0] = inv[0] = 1;
    for (int i=1; i<=n; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = inverse(fact[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    preprocess(n);
    int ret = 0;
    for (int i=1; i<=n; i++) {
        ret += choose(n / i - 1, k - 1);
        if (ret >= MOD) ret -= MOD;
    }
    cout << ret << "\n";

    return 0;
}