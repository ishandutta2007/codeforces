#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, m;
vector<int> a;

void read() {
    cin >> n >> m;
    a.resize(n);
    for (auto &i : a) {
        cin >> i;
        i %= m;
    }
}

const int MAXM = 1010;

bitset<MAXM> dp; 

void run() {
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp |= (dp << a[i]) | (dp >> (m - a[i]));
        dp[a[i]] = 1;
        if (dp[0]) {
            cout << "YES\n";
            exit(0);
        }
    }
}

void write() {
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}