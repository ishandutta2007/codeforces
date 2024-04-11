#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, l;
vector<int> a;
vector<int> ra;

ld calc(ld t, vector<int>& a) {
    ld myL = 0;
    int now = 0;
    for (int i = 0; i < n; ++i) {
        ld myLen = a[i] - now;
        ld needT = myLen / (i + 1);
        if (needT <= t) {
            t -= needT;
            myL = a[i];
        } else {
            myL += t * (i + 1);
            t = 0;
            break;
        }
        now = a[i];
    }
    myL += t * (n + 1);
    return min(myL, (ld)l);
}

bool check(ld t) {
    return calc(t, a) + calc(t, ra) >= l;
}

void solve() {
    cin >> n >> l;
    a.resize(n);
    for (auto& i : a) {
        cin >> i;
    }
    ra.resize(n);
    for (int i = 0; i < n; ++i) {
        ra[i] = l - a[i];
    }
    sort(all(ra));
    ld L = 0, R = l;
    for (int it = 0; it < 70; ++it) {
        ld M = (L + R) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}