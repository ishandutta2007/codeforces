#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll ans = 1, cur;
ll a10, ost;
int a[N], b[N], n, k;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n / k; i++) scanf("%d", a + i);
    for (int i = 0; i < n / k; i++) scanf("%d", b + i);

    a10 = 1;
    for (int i = 0; i < k; i++)
        a10 *= 10;

    for (int i = 0; i < n / k; i++) {
        cur = (a10 + a[i] - 1) / a[i];
        ost = b[i] % a[i];
        for (int j = 1; j < k; j++) {
            ost = (ost * 10) % a[i];
        }
        if (ost == 0) ost = a[i];
        cur -= (a10 / 10 + ost - 1) / a[i];
        ans = (ans * cur) % md;

        //cerr << cur << "\n";
    }

    cout << ans;



    return 0;
}