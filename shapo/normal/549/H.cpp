#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long double ld;
typedef long long ll;

ll a, b, c, d;

inline ld
get_min(ld a, ld b, ld eps)
{    
    return min(min((a - eps) * (b - eps), (a - eps) * (b + eps)), 
            min((a + eps) * (b - eps), (a + eps) * (b + eps)));
}

inline ld
get_max(ld a, ld b, ld eps)
{
    return max(max((a - eps) * (b - eps), (a - eps) * (b + eps)), 
            max((a + eps) * (b - eps), (a + eps) * (b + eps)));
}    

int
main()
{
    cout << fixed << setprecision(20);
    cin >> a >> b >> c >> d;
    ld ans = 0.; 
    if (a * d != b * c) {
        ld l = 0., r = max(max(abs(a), abs(b)), max(abs(c), abs(d)));
        for (int i = 0; i < 100; ++i) {
            ld eps = (l + r) / 2;
            ld l1 = get_min(a, d, eps), l2 = get_min(b, c, eps);
            ld r1 = get_max(a, d, eps), r2 = get_max(b, c, eps);
            if (max(l1, l2) < min(r1, r2)) {
                r = eps;
            } else {
                l = eps;
            }
        }
        ans = (l + r) / 2;
        ans = r;
        // cout << l << ' ' << r << '\n';
    }
    cout << ans << '\n';
    return 0;
}