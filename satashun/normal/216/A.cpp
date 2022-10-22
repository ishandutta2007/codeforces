#include <cstdio>
using namespace std;

int a, b, c, d, e, f, g, h, ans;

int main(){
    scanf("%d %d %d", &a, &b, &c);
    a--; b--; c--;
    d = a + b + c + 1;
    e = d * (d + 1) / 2;
    f = a * (a + 1) / 2;
    g = b * (b + 1) / 2;
    h = c * (c + 1) / 2;
    ans = e - f - g - h;
    printf("%d\n", ans);
    return 0;
}