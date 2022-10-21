#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int r1, r2, x, y, d;

int main() {
    cin >> r1 >> x >> r2 >> y;
    d = abs(x - y);
    ll ans = r1 + r2 + 1;
    for(int i = 1; i <= r1; i++) {
        int l = d - i, r = d + i;
        if(l >= 0) {
            l = min(l, r2);
            r = min(r, r2 + 1);
            ans += max(0, (r - l - 1) * 2 - 1);
        }
        else {
            l = -l;
            l = min(l, r2);
            r = min(r, r2 + 1);
            ans += max(0, (r - l - 1) * 2);
        }
    }
    cout << ans << endl;


}