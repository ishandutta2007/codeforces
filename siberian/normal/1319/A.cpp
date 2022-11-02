#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;
vector<int> b;

void read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i;
    b.resize(n);
    for (auto &i : b)
        cin >> i;
}

int ans = 1;

void run() {
    int sum1 = 0, sum2 = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] && !b[i]) cnt++;
        sum1 += a[i] == 1;
        sum2 += b[i] == 1;
    }
    if (cnt == 0) {
        cout << -1 << endl;
        exit(0);
    }
    if (sum1 > sum2) return;
    int need = sum2 - sum1 + 1;
    ans += (need + cnt - 1) / cnt;
}
 
void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}