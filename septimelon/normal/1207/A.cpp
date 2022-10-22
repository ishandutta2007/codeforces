#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, p, b, f, h, c;
    int ans;
    cin >> t;
    for (int qq = 0; qq < t; qq++) {
        cin >> b >> p >> f >> h >> c;
        b /= 2;
        if (h > c) {
            ans = min(b, p) * h;
            b = max(0, b - p);
            ans += min(b, f) * c;
        }
        else {
            ans = min(b, f) * c;
            b = max(0, b - f);
            ans += min(b, p) * h;
        }
        cout << ans << endl;
    }
    return 0;
}