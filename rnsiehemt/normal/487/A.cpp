#include <cstdio>
#include <algorithm>

int hy, ay, dy;
int hm, am, dm;
int hc, ac, dc;
int ans = 999999999;

int main()
{
    scanf("%d%d%d", &hy, &ay, &dy);
    scanf("%d%d%d", &hm, &am, &dm);
    scanf("%d%d%d", &hc, &ac, &dc);

    for (int d = 0; am-(dy+d) > 0; d++) {
        for (int h = 0; h < 20001; h++) {
            int amnew = am-(dy+d);
            int t = ((hy+h)+amnew-1)/amnew - 1;
            if (!t) continue;
            int aynew = (hm+t-1)/t + dm;
            ans = std::min(ans, hc*h + dc*d + std::max(0, aynew-ay)*ac);
        }
    }
    ans = std::min(ans, std::max(0, am-dy)*dc + std::max(0, dm-ay+1)*ac);
    printf("%d\n", ans);
}