#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iomanip>

using namespace std;

typedef double ld;

vector< int > l, r;
int n;

int
main()
{
    cin >> n;
    l.resize(n);
    r.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    ld ans = 0.;
    for (int i = 1; i <= 10000; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (j == k || i < l[k] || i > r[k]) {
                    continue;
                }
                ld mult = max(0., min(r[j] - l[j] + 1., r[j] - i - (j < k) + 1.));
                for (int ll = 0; ll < n; ++ll) {
                    if (ll != k && ll != j) {
                        mult *= max(0., min(r[ll] - l[ll] + 1., i - (ll > k) - l[ll] + 1.));
                    }
                }
                //cerr << i << " from " << j << " and " << k << " :" << mult << endl;
                ans += i * mult;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ans /= (r[i] - l[i] + 1.);
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}