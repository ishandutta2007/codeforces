#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //minimize a*k*x + t*(x - 1) + b*(d - a*k*x)
    //(a*k + t - a*b*k)x + b*d - t
    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;
    if(d <= k) {
        cout << a*d << '\n';
        return 0;
    }
    ll ans = b*d;
    ans = min(ans, a*k + b*(d - k));
    ll amt = d/k;
    ans = min(ans, amt*a*k + (amt - 1)*t + b*(d - amt*k));
    ans = min(ans, a*d + amt*t);
    cout << ans << '\n';
}