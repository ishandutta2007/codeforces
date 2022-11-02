#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, m;

void read() {
    cin >> n >> m;
}

int get(int x) {
    int ans = 0;
    while (x) {
        ans++;
        x /= 7;
    }
    chkmax(ans, 1);
    return ans;
}

int ans;

int get_mask(int x, int len) {
    int mask = 0;
    for (int i = 0; i < len; i++) {
        int bit = x % 7;
        if ((mask >> bit) & 1) return -1;
        mask |= (1 << bit);
        x /= 7;
    }
    return mask;
}

const int MAXGET = 8;

int cnt[1 << MAXGET];

void run() {
    if (get(n - 1) + get(m - 1) > 8) {
        ans = 0;
        return;
    }
    for (int i = 0; i < n; i++) {
        int have = get_mask(i, get(n - 1));
        if (have == -1) continue;
        cnt[have]++;
    }
    ans = 0;
    for (int i = 0; i < m; i++) {
        int have = get_mask(i, get(m - 1));
        if (have == -1) continue;
        have ^= ((1 << MAXGET) - 1);
        for (int submask = have; submask > 0; submask = (submask - 1) & have) {
            ans += cnt[submask];
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