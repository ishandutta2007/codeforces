#include <cstdio>
int main() {
    long long cur, n, sum = 0, min_odd = 2e9;
    scanf("%I64d", &n);
    while (n--) {
        scanf("%I64d", &cur);
        sum += cur;
        if ((cur & 1) && cur < min_odd)
            min_odd = cur;
    }
    printf("%I64d", (sum & 1) ? sum - min_odd : sum);
}