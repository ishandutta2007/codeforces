#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;

void read() {
    cin >> n;
}

ll cnk(ll n, ll k) {
    ll ans = 1;
    for (ll i = n - k + 1; i <= n; i++)
        ans *= i;
    for (ll i = 1; i <= k; i++)
        ans /= i;
    return ans;
}

ll ans;

void run() {
    ans = cnk(n, 5);
    ans *= ans;
    ans *= 120;
}

void write() {
    cout << ans << endl;
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