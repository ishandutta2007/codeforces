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

const int MOD = 998244353;

long long fact[300005], inv[300005];

long long inverse(long long a) {
    long long ret = 1;
    for (int b=MOD-2; b>0; b/=2) {
        if (b % 2) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

long long choose(int n, int k) {
    if (n < k) return 0;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        v.emplace_back(l, 1);
        v.emplace_back(r + 1, 0);
    }

    sort(v.begin(), v.end());
    fact[0] = inv[0] = 1;
    for (int i=1; i<=n; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = inverse(fact[i]);
    }

    int i = 0, cnt = 0;
    long long ret = 0;
    while (i < (int) v.size()) {
        int x = v[i].first, cur = 0;
        while (i < (int) v.size() && v[i].first == x) {
            if (v[i].second) {
                cnt++;
                cur++;
            } else {
                cnt--;
            }
            i++;
        }
        ret += (choose(cnt, k) - choose(cnt - cur, k) + MOD) % MOD;
        if (ret >= MOD) ret -= MOD;
    }
    cout << ret << "\n";

    return 0;
}