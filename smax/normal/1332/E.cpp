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
#define INV 499122177

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int div2(int a) {
    return (long long) a * INV % MOD;
}

int power(long long a, long long b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long n, m, l, r;
    cin >> n >> m >> l >> r;

    if (n * m % 2 == 1)
        cout << power(r - l + 1, n * m) << "\n";
    else {
        long long e = (r - l + 2) / 2, o = r - l + 1 - e;
        cout << div2(add(power(e + o, n * m), power(e - o + MOD, n * m))) << "\n";
    }

    return 0;
}