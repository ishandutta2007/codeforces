#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int d, r, n, ans = 0;
    cin >> r >> d >> n;
    while(n--) {
        int x, y, r1;
        cin >> x >> y >> r1;
        int l2 = x*x + y*y;
        if(r1*2 <= d && l2 >= (r + r1 - d)*(r + r1 - d) && l2 <= (r - r1)*(r - r1))
            ans++;
    }
    cout << ans << '\n';
}