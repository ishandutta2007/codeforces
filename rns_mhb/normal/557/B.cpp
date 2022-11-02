#include <bits/stdc++.h>
using namespace std;
#define N 3000100

int n, w, a[N];
double x, y, sum;

int main() {
    scanf("%d%d", &n, &w);
    for(int i = 0; i < 2 * n; i ++) scanf("%d", &a[i]);
    sort(a, a + 2 * n);
    x = a[0];
    y = a[n] / 2.0;
    if(x > y) x = y;
    sum = 3.0 * n * x;
    if(sum > w) sum = w;
    printf("%lf", sum);
}