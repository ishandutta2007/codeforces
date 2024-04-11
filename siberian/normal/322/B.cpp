#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int r, g, b;

void read() {
    cin >> r >> g >> b;
}

int ans;

void run() {
    ans = 0;
    for (int i = 0; i < 3; i++) {
        if (min(r, min(g, b)) < 0) continue;
        chkmax(ans, r / 3 + g / 3 + b / 3 + i);
        r--;
        g--;
        b--;
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