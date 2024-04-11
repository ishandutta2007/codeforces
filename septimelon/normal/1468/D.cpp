#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#else
    //    freopen("lupa.in","r",stdin);
    //    freopen("pupa.out","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10);
    cout << fixed;
    int t;
    cin >> t;
    while (--t >= 0) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<int> s(m);
        for (int &val: s) {
            cin >> val;
        }
        sort(s.begin(), s.end());
        int delta = abs(a - b);
        int len;
        if (a < b) {
            len = a;
        } else {
            len = n - a + 1;
        }
        int mn = 0, mx = min(delta, m + 1);
        while (mn + 1 < mx) {
            int md = mn + mx;
            md /= 2;
            bool det = true;
            for (int i = 0; i < md; ++i) {
                if (s[md - i - 1] > len + delta - 2 - i) {
                    det = false;
                    break;
                }
            }
            if (det) {
                mn = md;
            } else {
                mx = md;
            }
        }
        cout << mn << '\n';
    }
    return 0;
}