#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, c, t, a[123456];

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &c, &t);
        a[i] = c * t + (i ? a[i - 1] : 0);
    }
    while (m--) {
        cin >> t;
        printf("%d\n", 1 + lower_bound(a, a + n, t) - a);
    }
    return 0;
}