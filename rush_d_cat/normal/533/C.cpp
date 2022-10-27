#include <iostream>
#include <map>
using namespace std;
int xp, yp, xv, yv;
int dis(int x, int y) {
    return xp - x + yp - y;
}
int main() {
    scanf("%d%d%d%d", &xp, &yp, &xv, &yv);
    int t = 0;
    while (xv || yv) {
        if (min(xv, yv) >= 1) {
            -- xv, -- yv;
        } else if (xv) -- xv;
        else if (yv) -- yv;
        t ++;
        //printf("xv = %d, yv = %d\n", xv, yv);
        if (xv <= xp && yv <= yp) {
            //printf("t = %d, dis = %d\n", t, dis(xv, yv));
            if (dis(xv, yv) <= t) return !printf("Polycarp\n");
        }

    }
    return !printf("Vasiliy\n");
}