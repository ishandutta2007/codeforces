#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define MOD 998244353
#define INV 499122177

int p2[1000001], a[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    p2[0] = 1;
    for (int i=1; i<=n; i++)
        p2[i] = p2[i-1] * 2 % MOD;

    int ret = 0;
    for (int i=0; i<n; i++) {
        ret += (long long) p2[n-i] * a[i] % MOD;
        ret %= MOD;
        ret += (long long) p2[n-i-1] * (n - i - 1) % MOD * a[i] % MOD;
        ret %= MOD;
    }

    cout << (long long) ret * INV % MOD << "\n";

    return 0;
}