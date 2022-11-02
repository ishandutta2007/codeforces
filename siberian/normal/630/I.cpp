#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

//2434 ^ (n-3)+(n-3)4324 ^ (n-4)

int n;

void read() {
    cin >> n;
}

ll pow(ll a, ll n) {
    ll ans = 1;
    for (ll i = 0; i < n; i++)
        ans = ans * a;
    return ans;
}

ll ans;

void run() {
    ans += (ll) 2 * 4 * 3 * pow(4, n - 3);
    ans += (ll) (n - 3) * 4 * pow(3, 2) * pow(4, n - 4);
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