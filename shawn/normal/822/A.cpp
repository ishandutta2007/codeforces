#include <cstdio>
#include <algorithm>

using namespace std;

int a, b;
int main() {
    scanf("%d%d", &a, &b);
    a = min(a, b);
    long long ans = 1;
    for (int i = 2; i <= a; i ++) {
        ans *= i;
    }
    printf("%d\n", ans);
    return 0;
}