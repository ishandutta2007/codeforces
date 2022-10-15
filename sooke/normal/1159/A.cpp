#include <cstdio>
#include <algorithm>

const int N = 105;

int n, now, min;
char str[N];

int main() {
    scanf("%d%s", &n, str);
    for (int i = 0; i < n; i++) {
        if (str[i] == '+') { now++; } else { now--; }
        min = std::min(min, now);
    }
    printf("%d\n", now - min);
    return 0;
}