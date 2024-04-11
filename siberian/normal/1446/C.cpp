#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;
int n;
int a[N];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
}

int solve(int l, int r, int bit) {
    if (l >= r) return 0;
    if (l == r - 1) return 1;
    int pos = l;
    while (pos < r && !((a[pos] >> bit) & 1)) ++pos;
    int L = solve(l, pos, bit - 1);
    int R = solve(pos, r, bit - 1);
    int ans = max(L, R);
    if (pos > l) {
        chkmax(ans, R + 1);
    }
    if (pos < r) {
        chkmax(ans, L + 1);
    }
    return ans;
}

int ans;

void run() {
    ans = n - solve(0, n, 29);
}

void write() {
    cout << ans << '\n';
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