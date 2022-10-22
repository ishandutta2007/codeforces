#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans = 0;
    int buf;
    if (e >= f) {
        buf = min(a, d);
        ans += buf * e;
        d -= buf;
        a -= buf;
    }
    buf = min({b, c, d});
    ans += buf * f;
    d -= buf;
    ans += min(a, d) * e;
    cout << ans << '\n';
    return 0;
}