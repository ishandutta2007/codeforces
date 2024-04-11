#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

ll n;

void read() {
    cin >> n;
}

int ans;

void run() {
    ans = 0;
    ll x = 1;
    ll last = 1;
    while (x + last <= n) {
        //cout << x << " " << last << endl;
        ans++;
        ll help = last;
        last = x;
        x += help;
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