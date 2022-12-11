//made by Sert
#include <cstdio>
int main() {
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    int mnr = n, mxl = 1;
    while (m--) {
        scanf("%d%d", &l, &r);
        if (l > r) l ^= r ^= l ^= r;
        mxl = (l > mxl ? l : mxl);
        mnr = (r < mnr ? r : mnr);
    }
    printf((mnr > mxl ? "%d\n" : "0\n"), mnr - mxl);
    return 0;
}