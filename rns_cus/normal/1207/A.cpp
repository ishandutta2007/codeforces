#include <bits/stdc++.h>
using namespace std;

#define N

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int b, p, f, h, c;
        scanf("%d %d %d %d %d", &b, &p, &f, &h, &c);
        if (h < c) swap(h, c), swap(p, f);
        int rlt = 0;
        while (b >= 2 && max(p, f) > 0) {
            if (p > 0) rlt += h, p --;
            else rlt += c, f --;
            b -= 2;
        }
        printf("%d\n", rlt);
    }

    return 0;
}