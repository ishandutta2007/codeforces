#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k, ans, a1, a2, a3;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            k = min(a[j], a[j + 3]);
            t = a[j + 1] + a[j + 2];
            ans += k * t * 2ll;
            a[j] -= k;
            a[j + 3] -= k;
        }
    }

    a1 = max(a[0], a[3]);

    ans += a1 * a1;

    cout << ans;

    return 0;
}