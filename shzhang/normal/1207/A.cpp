#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cmath>

int t;

#define amin(a, b) (a < b ? a : b)

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int b, p, f, h, c;
        scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
        b /= 2;
        int ans;
        if (h < c) {
            ans = amin(b, f) * c;
            b -= amin(b, f);
            ans += amin(b, p) * h;
        } else {
            ans = amin(b, p) * h;
            b -= amin(b, p);
            ans += amin(b, f) * c;
        }
        printf("%d\n", ans);
    }
    return 0;
}