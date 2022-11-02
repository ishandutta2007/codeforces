#include <bits/stdc++.h>
using namespace std;

int func(int k) {
    if (k % 400 == 0) return 366;
    if (k % 100 == 0) return 365;
    if (k % 4 == 0) return 366;
    return 365;
}

int main() {
    int y, ans = 0;
    scanf("%d", &y);
	int x = func(y);
	ans = x % 7;
    for (int i = y + 1; ; i ++) {
        y = func(i);
        if (!ans && x == y) {printf("%d\n", i); return 0;}
        ans = (ans + y) % 7;
    }
}