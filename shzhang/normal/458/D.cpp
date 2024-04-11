#include <cstdio>
#include <cmath>

using namespace std;

#define ld long double

ld fact[100005];

ld C(int a, int b)
{
    return fact[a] - fact[b] - fact[a-b];
}

ld A(int a, int b)
{
    return fact[a] - fact[a-b];
}

int n, m, k;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    fact[0] = 0.0;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = fact[i-1] + log((ld)(i));
    }
    ld ans = 0.0;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            int cnt = n * (x + y) - x * y;
            if (cnt > k) continue;
            ans += exp(C(n, x) + C(n, y) + A(k, cnt)
                + fact[m - cnt] - fact[m]);
        }
    }
    if (ans > 1e99) {
        printf("1e99");
    } else {
        printf("%.15Le", ans);
    }
    return 0;
}