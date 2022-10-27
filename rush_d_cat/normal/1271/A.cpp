#include <iostream>
using namespace std;
typedef long long LL;
int a, b, c, d, e, f;

LL ans = 0;
int main() {
    cin >> a >> b >> c >> d >> e >> f;
    for (int x = 0; x <= min(a, d); x ++) {
        LL tmp = 1LL * x * e;
        d -= x;
        tmp += 1LL * min(min(b, c), d) * f;
        d += x;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}