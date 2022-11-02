#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;
const int LOG = 30;
int n;
int a[N];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

ll pref[N];

void init() {
    for (int i = 0; i < n; ++i) {
        pref[i] = a[i];
        if (i > 0) {
            pref[i] += pref[i - 1];
        }
    }
}

bool check(int l, int r) {
    if (r - l < 2) return false;
    int L = a[l] ^ a[r];
    ll R = pref[r - 1] - pref[l];
    return L == R;
}

int last[LOG][2];
int ans;

void relax(int l, int r, int bit) {
    assert(((a[l] ^ a[r]) >> bit) & 1);
    if (((a[l] ^ a[r]) >> (bit + 1))) return;
    if (check(l, r)) {
        ++ans;
    }
}

void solve() {
    init();
    for (int bit = 0; bit < LOG; ++bit) {
        for (int it = 0; it < 2; ++it) {
            last[bit][it] = -1; 
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int bit = 0; bit < LOG; ++bit) {
            if ((a[i] >> bit) & 1) continue;
            for (int it = 0; it < 2; ++it) {
                if (last[bit][it] == -1) continue;
                relax(last[bit][it], i, bit);
            }
        }
        for (int bit = 0; bit < LOG; ++bit) {
            if ((a[i] >> bit) & 1) {
                last[bit][0] = last[bit][1];
                last[bit][1] = i;
            }
        }
    }
}

void run() {
    ans = 0;
    solve();
    reverse(a, a + n);
    solve();
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