#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18 + 13;
const int N = 1e7 + 1003;
//const int M = 1e5 + 13;
const int A = 26;

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    li a, b, c, d, l, r;
    cin >> a >> b >> c >> d >> l >> r;

    if(c > a) {
        swap(a, c);
        swap(b, d);
    }

    if(a >= 100) {
        li ans = 0;
        li cur = b;
        while(cur <= r) {
            if(cur >= l && (cur - d) >= 0 && (cur - d) % c == 0)
                ans++;


            cur += a;
        }

        cout << ans << endl;
        return 0;
    }

    if(b < d) {
        b += (d - b) / a * a;
    } else {
        d += (b - d) / c * c;
    }

    int cur = 0;
    while(cur < 1e7 + 13 && b != d) {
        cur++;

        if(b < d)
            b += a;
        else
            d += c;
    }

//    cout << b << ' ' << d << endl;

    if(b != d || b > r) {
        cout << 0 << endl;
        return 0;
    }

    li g = __gcd(a, c);

    li x = c / g;
    li y = a / g;

    li a1 = a * 1ll * x;

//    cout << a1 << endl;

    if(b < l) {
        b += (l - b + a1 - 1) / a1 * a1;
    }

    li ans = (r >= b ? (r - b) / a1 + 1 : 0ll);

    cout << ans << endl;
}