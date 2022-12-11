#include <bits/stdc++.h>
using namespace std;
int main() {
    long long ans = 1;
    int n, num = 0, cur, was1 = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &cur);
        if (cur == 0 && was1)
            num++;
        if (cur == 1) {
            ans *= num + (was1 = 1);
            num = 0;
        }
    }
    printf("%I64d", ans * was1);
}