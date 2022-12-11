#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long n, m, a[123456], b[123456], t, l, r;

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; b[i] += b[i - 1], a[i] += a[i - 1], i++);
    cin >> m;
    while (m--) {
        cin >> t >> l >> r;
        printf("%I64d\n", (t == 1 ? a[r] - a[l - 1] : b[r] - b[l - 1]));
    }
    return 0;
}