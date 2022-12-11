#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 4;
typedef long long ll;
typedef long double ld;
const ll md = 1e9 + 9;
const ll p1 = 997;
const ll p2 = 2011;

ll n, h, k, c, ans, x;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n >> h >> k;
    while (n--) {
        cin >> x;
        if (x + c > h) {
            c = 0;
            ans++;
        }
        c += x;
        ans += c / k;
        c %= k;
    }
    cout << ans + !!c;

    return 0;
}