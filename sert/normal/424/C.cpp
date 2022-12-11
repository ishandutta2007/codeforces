#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

int n, ans, x;
int xr[N];

int main() {
    //freopen("a.in", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        ans ^= x;
    }

    for (int i = 1; i < N; i++)
        xr[i] = xr[i - 1] ^ i;

    for (int i = 2; i <= n; i++) {
        x = n % (i * 2);
        if (x < i)
            ans ^= xr[x];
        else {
            ans ^= xr[i - 1];
            ans ^= xr[x - i];
        }
    }

    cout << ans;

    return 0;
}