#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    //freopen("a.in", "r", stdin);
    int n, x, sum = 0, ans, a = 0, t, b = 0;
    scanf("%d", &n);

    for (int i = 0; i < n * 2; i++) {
        scanf("%d.%d", &t, &x);
        //cerr << x << "\n";
        sum -= x;
        if (x != 0)
            a++;
        else
            b++;
    }

    a = min(a, n);
    b = max(0, n - b);
    sum += 1000 * b;
    ans = abs(sum);

    for (int i = b; i < a; i++) {
        sum += 1000;
        ans = min(ans, abs(sum));
    }

    printf("%d.%03d", ans / 1000, ans % 1000);

    return 0;
}