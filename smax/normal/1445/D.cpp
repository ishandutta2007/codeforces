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

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

long long inverse(long long a) {
    long long ret = 1;
    for (int b=MOD-2; b>0; b/=2) {
        if (b % 2) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(2*n);
    for (int i=0; i<2*n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    int ret = 0;
    long long choose = 1;
    for (int i=0; i<n; i++) {
        add(ret, (a[2*n-i-1] - a[i]) % MOD);
        choose = choose * (2 * n - i) % MOD * inverse(i + 1) % MOD;
    }
    DEBUG(ret)
    cout << ret * choose % MOD << "\n";

    return 0;
}