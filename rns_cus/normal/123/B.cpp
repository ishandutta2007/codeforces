#include <bits/stdc++.h>
using namespace std;

int fab(int x) {
    return x < 0 ? -x : x;
}
int main() {
    //freopen("1.in", "r", stdin);
    int a, b , x, y, x1, y1;
    scanf("%d%d%d%d%d%d", &a, &b, &x, &y, &x1, &y1);
    ///swap(a, b);
    int x2 = x;
    x = x + y;
    y = x2 - y;
    x2 = x1;
    x1 = x1 + y1;
    y1 = x2 - y1;
    a *= 2;
    b *= 2;
    if(x <= 0) x = x / a - 1;
    else x /= a;
    if(y <= 0) y = y /b - 1;
    else y /= b;
    if(x1 <= 0) x1 = x1 / a - 1;
    else x1 /= a;
    if(y1 <= 0) y1 = y1 / b - 1;
    else y1 /= b;
    printf("%d\n", max(fab(x - x1) , fab(y - y1)));
    return 0;
}