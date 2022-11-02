#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b, ans = 0;
	scanf("%d %d %d", &n, &a, &b);
    for (int k = 1; k <= min(a, b); k ++) {
        if (a / k + b / k >= n) ans = k;
        else break;
    }
    printf("%d\n", ans);
}