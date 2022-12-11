#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

char ch;
set <char> s;
long long n, a[345656], ans;

int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    if (n == 1) {
        printf("%I64d\n", a[0]);
        return 0;
    }
    for (int i = 0; i < n; i++)
        ans += a[i] * min(i + 2ll, n);
    printf("%I64d", ans);
    return 0;
}