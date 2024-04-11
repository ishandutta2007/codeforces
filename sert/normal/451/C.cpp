#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 800;
const ll md = 1e9 + 7;

ll n, k, d1, d2, t, sum;

bool check(ll a, ll b, ll c) {
    if (a + b + c > k)
        return false;
    if ((k - a - b - c) % 3)
        return false;
    if (c * 2 - a - b <= n - k && (n - k - c * 2 + a + b) % 3 == 0)
        return true;
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d", &t);
    while (t--) {
        scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);

        if (check(0, d2, d1 + d2)) {
            cout << "yes\n";
            continue;
        }
        if (check(0, d1, d1 + d2)) {
            cout << "yes\n";
            continue;
        }
        if (d1 > d2) swap(d1, d2);
        if (check(0, d1, d2)) {
            cout << "yes\n";
            continue;
        }

        if (check(0, d2 - d1, d2)) {
            cout << "yes\n";
            continue;
        }

        cout << "no\n";

    }


    return 0;
}