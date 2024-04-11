#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
const ld EPS = 1e-10;
const ld INF = (ll)1e9 + 34;
const ll N = (ll)1e6 + 34;

int a[N];
int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    cout << min(min(abs(x - a[0]) + abs(a[0] - a[n - 2]), abs(x - a[n - 2]) + abs(a[n - 2] - a[0])),
                min(abs(x - a[1]) + abs(a[1] - a[n - 1]), abs(x - a[n - 1]) + abs(a[n - 1] - a[1])));
    return 0;
}