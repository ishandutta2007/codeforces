#include <bits/stdc++.h>
using namespace std;

int n, m;

bool test(int k) {
    if (!k) return 0;
    int a = k / 2, b = k / 3, c = k / 6;
    a -= c, b -= c;
    if (n > a + c) return 0;
    if (m > b + c) return 0;
    if (n + m > a + b + c) return 0;
    return 1;
}

int main() {
    scanf("%d %d", &n, &m);
    int st = 0, en = 1000000000;
    while (st < en) {
        int mid = st + en >> 1;
        if (test(mid)) en = mid;
        else st = mid + 1;
    }
    printf("%d\n", st);
}