#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define MOD 998244353

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int mul(int a, int b) {
    return (long long) a * b % MOD;
}

int power(long long a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

int inverse(long long a) {
    int ret = 1, b = MOD - 2;
    while (b > 0) {
        if (b & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

int fact[200001], inv[200001];

int choose(int n, int k) {
    return mul(fact[n], mul(inv[k], inv[n-k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    if (n == 2) {
        cout << "0\n";
        return 0;
    }

    fact[0] = inv[0] = 1;
    for (int i=1; i<=m; i++) {
        fact[i] = mul(fact[i-1], i);
        inv[i] = inverse(fact[i]);
    }

    int ret = 0, pow2 = power(2, n-3);
    for (int p=n-1; p<=m; p++)
        add(ret, mul(p-1, mul(choose(p-2, n-3), pow2)));

    cout << ret << "\n";

    return 0;
}