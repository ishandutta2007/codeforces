#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, y;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int val; scanf("%d", &val);
        if (val == 1) x ++;
        if (val == 2) y ++;
    }
    int ans = min(x, y);
    if (x > y) ans += (x - y) / 3;
    printf("%d\n", ans);
}