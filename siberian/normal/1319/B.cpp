#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}
#define int ll
int n;
vector<int> b;

void read() {
    cin >> n;
    b.resize(n);
    for (auto &i : b)
        cin >> i;
}

map<int, int> fans;
int ans;

void run() {
    for (int i = 0; i < n; i++) {
        fans[i - b[i]] += b[i];
    }
    ans = 0;
    for (auto i : fans)
        chkmax(ans, i.second);
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