#include <bits/stdc++.h>
using namespace std;
const int seg[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main() {
    int a, b, x, ans = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        x = i;
        while (x > 0) {
            ans += seg[x % 10];
            x /= 10;
        }
    }
    printf("%d", ans);
}