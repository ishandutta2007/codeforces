#include <cstdio>
#include <algorithm>
long long n, m, ans;
int main() {
    scanf("%I64d%I64d", &n, &m);
    while (n * m >= 2) {
        //printf("%d %d\n", n, m);
        if (n > m)
            {n -= 2; m--;}
        else
            {m -= 2; n--;}
        ans++;
    }
    printf("%I64d", ans);
    return 0;
}