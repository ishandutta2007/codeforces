#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    long long n, h, ans, lv = 0;
    cin >> n >> h;
    ans = n;
    h = (1ll << n) + h - 1;
    long long pr = 1 - h % 2;
    //cout << ans << "\n";
    while (h != 0) {
        if (h % 2 != pr) {
            h /= 2;
            pr = 1 - pr;
            lv++;
            continue;
        }
        ans += (1ll << lv) - 1;
        h /= 2;
        lv++;
    }
    cout << ans;
}