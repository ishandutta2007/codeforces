#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int b, p, f, h, c, ans = 0;
        cin >> b >> p >> f >> h >> c;
        if(h > c) {
            int amt = min(b/2, p);
            ans += amt * h;
            b -= 2*amt;
            amt = min(b/2, f);
            ans += amt * c;
        }
        else {
            int amt = min(b/2, f);
            ans += amt * c;
            b -= 2*amt;
            amt = min(b/2, p);
            ans += amt * h;
        }
        cout << ans << '\n';
    }
}