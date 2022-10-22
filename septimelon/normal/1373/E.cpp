#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void printv(vector<ll> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

ll min_with_f(int f) {
    ll ans = f % 9;
    while (f > 8) {
        ans = ans * 10 + 9;
        f -= 9;
    }
    return ans;
}

ll min_with_f_and_nines(int f, int c9) {
    if (c9 * 9 > f) {
        return -1LL;
    }
    f -= 9 * c9;
    ll ans;
    if (f > 7) {
        ans = min_with_f(f - 8) * 10 + 8;
    } else {
        ans = f;
    }
    for (int i = 0; i < c9; ++i) {
        ans = ans * 10 + 9;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    ll ans = -1LL;
    for (int z = 0; z < 10; ++z) {
        int d1 = min(k + 1, 10 - z);
        int d2 = max(0, z + k - 9);
        int cn = n - d1 * (d1 - 1) / 2 - d2 * (d2 - 1) / 2 - d2 - z * d1;
        if (cn < 0) {
            continue;
        }
        if (d2 > 0) {
            for (int q = 0; cn + 9 * q * d2 >= (k + 1) * 9 * q; ++q) {
                if ((cn + 9 * q * d2) % (k + 1) != 0) {
                    continue;
                }
                if (min_with_f_and_nines((cn + 9 * q * d2) / (k + 1), q) == -1) {
                    break;
                }
                //cout << z << " " << q << " " << min_with_f_and_nines((cn + 9 * q * d2) / (k + 1), q) << "\n";
                if (ans == -1LL) {
                    ans = min_with_f_and_nines((cn + 9 * q * d2) / (k + 1), q) * 10 + z;
                } else {
                    ans = min(ans, min_with_f_and_nines((cn + 9 * q * d2) / (k + 1), q) * 10 + z);
                }
            }
        } else {
            if (cn % (k + 1) == 0) {
                //cout << z << " _ " << min_with_f(cn / (k + 1)) << "\n";
                if (ans == -1LL) {
                    ans = min_with_f(cn / (k + 1)) * 10 + z;
                } else {
                    ans = min(ans, min_with_f(cn / (k + 1)) * 10 + z);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}