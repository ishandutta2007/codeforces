#include <bits/stdc++.h>

using namespace std;
using li = long long;
using ld = long double;

int main() {
    int n, x, k;
    cin >> n >> x >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if(x * 1ll * k > 2e9) {
        cout << 0;
        return 0;
    }

    li ans = 0;
    for(int i = 0; i < n; i++) {
        int j = (lower_bound(a.begin(), a.end(), a[i]) - a.begin() - 1);
        int l = j, r = n;
        while(r - l > 1) {
            int m = (l + r) / 2;

            if(a[m] / x - (a[i] - 1) / x > k)
                r = m;
            else
                l = m;
        }

        int rg = r;

        l = j, r = n;
        while(r - l > 1) {
            int m = (l + r) / 2;

//            cout << l << ' ' << r << ' ' << endl;

            if(a[m] / x - (a[i] - 1) / x >= k)
                r = m;
            else
                l = m;
        }

        int lf = r;

        ans += (rg - lf);
//        cout << a[i] << ' ' << lf << ' ' << rg << endl;
    }

    cout << ans;
}