#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, x, y, c;
pair <int, int> a[1234567];
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        a[i] = make_pair(x + y, i);
        c += y - x;
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--)
    if (c >= 0) {
        c -= a[i].first;
        a[i].first = a[i].second;
        a[i].second = -1;
    } else {
        c += a[i].first;
        a[i].first = a[i].second;
        a[i].second = -2;
    }
    sort(a, a + n);
    if (c < -1000 || c > 1000) cout << -1;
    else for (int i = 0; i < n; i++) printf("%c", (a[i].second == -1 ? 'A' : 'G'));
}