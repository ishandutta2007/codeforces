#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int h, c, t;

ld calc(ld a) {
    return abs((a * h + (a - 1) * c) / (2 * a - 1) - t);
}

void solve() {
    cin >> h >> c >> t;
    if (t == h) {
        cout << 1 << "\n";
        return;
    }
    if (t - c == h - t) {
        cout << 2 << "\n";
        return;
    }
    if (t - c < h - t) {
        cout << 2 << "\n";
        return;
    }
    int l = 0, r = 1e7 + 228 + 1337;
    while (r - l > 2) {
        int mid1 = (2 * l + r) / 3;
        int mid2 = (l + 2 * r) / 3;
        if (calc(mid1) <= calc(mid2)) {
        	r = mid2;
        }
        else {
        	l = mid1;
        }
    }
    ld ans = 1e9;
    int fans = 0;
    for (int i = max(1ll, l - 5); i <= r + 5; i++) {
        if (calc(i) < ans) {
            ans = calc(i);
            fans = i;
        }
    }
    //cout << calc(fans) << endl;
    //cout << calc(3) << endl; 
    //cout << "fans = " << fans << endl;
    cout << 2 * fans - 1 << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}