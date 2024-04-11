#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
ll l, r;

void read() {
    cin >> l >> r;
}

ll pow(int len) {
    ll ans = 1;
    for (int i = 0; i < len - 1; i++)
        ans *= 10;
    return ans;
} 

ll find_up(ll x, int len) {
    int tl = -1, tr = pow(len - 1) - 1;
    while (tl < tr - 1) {
        int tm = (tl + tr) / 2;
        if (tm * 10 + x >= l)
            tr = tm;
        else
            tl = tm;
    }
    return tr;
}

ll find_down(ll y, int len) {
    int tl = -1, tr = pow(len - 1) - 1;
    while (tl < tr - 1) {
        int tm = (tl + tr) / 2;
        if (y - tm * 10 <= r)
            tr = tm;
        else
            tl = tm;
    }
    return pow(len - 1) - 1 - tr;
}

ll cross(ll x, ll y, int len) {
    return find_down(y, len) - find_up(x, len) + 1;
}

ll calc(int len, int num) {
    ll x = pow(len) * num + (len > 1 ? num : 0);
    if (x > r) return 0; 
    ll y = x;
    int have = 1;
    for (int i = 1; i < len - 1; i++) {
        have *= 10;
        y += have * 9;
    }
    if (y < l) return 0;
 //   cout << x << " " << y << endl;
    return cross(x, y, len);
}

ll ans = 0;

void run() {
    for (int len = 1; len <= 18; len++) {
        for (int num = 1; num <= 9; num++) {
   //         cout << calc(len, num) << endl;
            ans += calc(len, num);
        }
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