#include <cstdio>
#include <iostream>
using namespace std;

int t, n, x, y, minx, miny, maxx, maxy;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        minx = 0;
        miny = 0;
        maxx = 0;
        maxy = 0;
        while(n--){
            scanf("%d%d", &x, &y);
            minx = min(minx, x);
            miny = min(miny, y);
            maxx = max(maxx, x);
            maxy = max(maxy, y);
        }
        printf("%d\n", (maxx - minx + maxy - miny) * 2);
    }
    return 0;
}