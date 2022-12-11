#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

string s;
ll n, l, m, ans, mx;
ll p[N], h[N], a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < mx)
            h[i] = mx - a[i];
        else
            mx = a[i];
    }

    for (int i = 1; i < n; i++)
        ans += max(0ll, h[i] - h[i - 1]);
    cout << ans;



    return 0;
}