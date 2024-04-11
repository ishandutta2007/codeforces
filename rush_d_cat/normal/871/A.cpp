#include <iostream>
using namespace std;
// 4,6,9,14,21

// 4x: x
// 4x+1  1 + x - 2  9+ 4x-8
// 4x+2  x          6+ 4x-4
// 4x+3  4*(x-3) + 6 + 9

int q, n, ans;
int main() {
    scanf("%d", &q);
    while (q --) {
        scanf("%d", &n);
        if (n % 4 == 0 || n % 4 == 2) {
            ans = n / 4;
        }
        if (n % 4 == 1 || n % 4 == 3) {
            ans = n / 4 - 1;
        }
        if (ans == 0 || n == 11) ans = -1;
        printf("%d\n", ans);
    }
}