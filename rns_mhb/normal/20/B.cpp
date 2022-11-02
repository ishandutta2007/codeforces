#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a == 0) {
        if(b == 0) {
            if(c == 0) puts("-1");
            else puts("0");
        } else {
            puts("1");
            printf("%.10lf\n", -1.0 * c / b);
        }
    } else {
        long long D = 1ll * b * b - 4ll * a * c;
        if(D < 0) puts("0");
        else if(D == 0) {
            puts("1");
            printf("%.10lf\n", -0.5 * b / a);
        } else {
            double d = sqrt(D);
            puts("2");
            double x1 = (d - b) / (2 * a);
            double x2 = (-d - b) / (2 * a);
            printf("%.10lf\n%.10lf\n", min(x1, x2), max(x1, x2));
        }
    }
}