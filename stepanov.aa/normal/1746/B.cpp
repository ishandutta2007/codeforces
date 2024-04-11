#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define flt double
#define all(a) a.begin(), a.end()

int n;
vector<int> a;

int32_t main() {
    if (1) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
        }
        int rs = 0;
        int zc = 0;
        for (int i = 0; i < n; i += 1) {
            if (a[i] == 0) {
                rs += 1;
                zc += 1;
            }
        }
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i += 1) {
            p[i] = p[i - 1] + a[i - 1];
        }
        int cnt = p[n];
        int oc1 = 0;
        int oc2 = cnt;
        int zc1 = 0;
        int zc2 = zc;
        for (int i = 0; i < n; i += 1) {
            if (a[i] == 1) {
                rs = max(rs, zc1 + oc2 + min(oc1, zc2));
                oc1 += 1;
                oc2 -= 1;
            } else {
                zc1 += 1;
                zc2 -= 1;
            }
        }
        cout << n - rs << "\n";
    }
    return 0;
}