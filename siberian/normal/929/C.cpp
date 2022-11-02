#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e3 + 10;
int n[3];
int a[3][MAXN];

void read() {
    for (int i = 0; i < 3; i++)
        cin >> n[i];
    for (int x = 0; x < 3; x++) {
        for (int i = 0; i < n[x]; i++) {
            cin >> a[x][i];
        }
        sort(a[x], a[x] + n[x]);
    }
}

ll cnk(ll n, ll k) {
    if (k == 1) return n;
    if (k == 2) return n * (n - 1) / 2;
    return n * (n - 1) * (n - 2) / 6;
}

ll ans;

void run() {
    for (int i = 0; i < n[0]; i++) {
        int cnt1 = upper_bound(a[1], a[1] + n[1], 2 * a[0][i]) - lower_bound(a[1], a[1] + n[1], a[0][i]);
        int cnt2 = upper_bound(a[2], a[2] + n[2], 2 * a[0][i]) - lower_bound(a[2], a[2] + n[2], a[0][i]);
        ans += cnk(cnt1, 2) * cnk(cnt2, 3);
    }
    for (int i = 0; i < n[1]; i++) {
        int cnt0 = upper_bound(a[0], a[0] + n[0], 2 * a[1][i]) - lower_bound(a[0], a[0] + n[0], a[1][i]);
        int cnt1 = upper_bound(a[1], a[1] + n[1], 2 * a[1][i]) - lower_bound(a[1], a[1] + n[1], a[1][i] + 1);
        int cnt2 = upper_bound(a[2], a[2] + n[2], 2 * a[1][i]) - lower_bound(a[2], a[2] + n[2], a[1][i]);
        ans += cnk(cnt0, 1) * cnk(cnt1, 1) * cnk(cnt2, 3);
    }
    for (int i = 0; i < n[2]; i++) {
        int cnt0 = upper_bound(a[0], a[0] + n[0], 2 * a[2][i]) - lower_bound(a[0], a[0] + n[0], a[2][i]);
        int cnt1 = upper_bound(a[1], a[1] + n[1], 2 * a[2][i]) - lower_bound(a[1], a[1] + n[1], a[2][i]);
        int cnt2 = upper_bound(a[2], a[2] + n[2], 2 * a[2][i]) - lower_bound(a[2], a[2] + n[2], a[2][i] + 1);
        ans += cnk(cnt0, 1) * cnk(cnt1, 2) * cnk(cnt2, 2);
    }
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