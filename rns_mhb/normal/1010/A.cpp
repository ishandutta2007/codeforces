#include<bits/stdc++.h>
using namespace std;

int a[2020];

int main() {
    int n;
    scanf("%d", &n);
    double m;
    scanf("%lf", &m);
    for(int i = 1; i <= 2 * n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= 2 * n; i ++) if(a[i] == 1) {
        puts("-1");
        return 0;
    }
    double x = 1;
    for(int i = 1; i <= 2 * n; i ++) x *= 1.0 * (a[i] - 1) / a[i];
    double y = m / x - m;
    printf("%.7lf\n", y);
}