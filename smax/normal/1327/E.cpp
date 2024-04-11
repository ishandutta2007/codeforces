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

int power[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    power[0] = 1;
    for (int i=1; i<=n; i++)
        power[i] = mul(power[i-1], 10);

    for (int i=1; i<n; i++) {
        int ret = 0;
        if (i < n - 1)
            add(ret, mul(mul(810, n - i - 1), power[n-i-2]));
        add(ret, mul(180, power[n-i-1]));
        cout << ret << " ";
    }
    cout << "10\n";

    return 0;
}