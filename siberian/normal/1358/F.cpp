#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void no() {
    cout << "IMPOSSIBLE" << endl;
    exit(0);
}

void big(ll ans) {
    cout << "BIG" << endl;
    cout << ans << endl;
    exit(0);
}

void small(string ans) {
    cout << "SMALL" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
    exit(0);
}

int n;
vector<ll> a, b;

bool checkSorted(vector<ll> & a) {
    for (int i = 1; i < (ll) a.size(); i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

void relax(vector<ll> & a) {
    for (int i = (ll)a.size() - 1; i > 0; i--) {
        a[i] -= a[i - 1];
    }
}

bool check() {
    if (*min_element(all(a)) > *min_element(all(b))) no();
    bool ans = a == b;
    reverse(all(a));
    ans |= a == b;
    reverse(all(a));
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.setf(ios::fixed), cout.precision(20);
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
        cin >> i;
    }
    b.resize(n);
    for (auto &i : b) {
        cin >> i;
    }
    if (n == 1) {
        if (a != b) no();
        small("");
    }
    if (n == 2) {
        string ans = "";
        ll len = 0;
        bool ok = true;
        while (!check()) {
            ll mxB = *max_element(all(b));
            ll mnB = *min_element(all(b));
            ll mxA = *max_element(all(a));
          
            if (*min_element(all(a)) == *min_element(all(b))) {

                if ((mxB - mxA) % mnB) no();

                if (!checkSorted(b)) {
                    ans += 'R';
                    reverse(all(b));
                }

                ll cnt_add = (mxB - mxA) / mnB;
                len += cnt_add;
                if (!ok || cnt_add + (int)ans.size() > 5e5 - 10) {
                    ok = false;
                } else {
                    while(cnt_add--) {
                        ans += 'P';
                    }
                }
                break;
            }

            if (!checkSorted(b)) {
                ans += 'R';
                reverse(all(b));
            }

            ll cnt_add = mxB / mnB;
            len += cnt_add;
            if (!ok || cnt_add + (int)ans.size() > 5e5 - 10) {
                ok = false;
            } else {
                while(cnt_add--) {
                    ans += 'P';
                }
            }

            b[1] %= b[0];
        }

        if (a != b) {
            ans += 'R';
        }

        if (len > 200000) big(len);
        reverse(all(ans));
        small(ans);
    }

    string ans = "";
    ll len = 0;
    while (!check()) {
        if (!checkSorted(b)) {
            ans += 'R';
            reverse(all(b));
        }
        len++;
        ans += 'P';
        relax(b);
    }

    if (a != b) {
        ans += 'R';
    }

    reverse(all(ans));
    if (len <= 200000) small(ans);
    big(len);
    return 0;
}