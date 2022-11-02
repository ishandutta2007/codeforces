#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, d;
    scanf("%d", &t);
    while(t --) {
        scanf("%d", &d);
        if(d * d < 4 * d) {
            puts("N");
            continue;
        }
        double a = 0.5 * (d + sqrt(d*d-4*d));
        double b = d - a;
        printf("Y %.10lf %.10lf\n", a, b);
    }
}