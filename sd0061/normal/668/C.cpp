#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n;
double c[N] , d[N] , a[N] , b[N];

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%lf" , &c[i]);
    }
    for (int i = 2 ; i <= n ; ++ i) {
        c[i] += c[i - 1];
    }
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%lf" , &d[i]);
    }
    for (int i = n - 1 ; i > 0 ; -- i) {
        d[i] += d[i + 1];
    }
    a[n] = b[n] = 1;
    for (int i = 1 ; i < n ; ++ i) {
        double x = c[i] - d[i + 1] + 1 , y = c[i];
        double D = sqrt(max(0.0 , x * x - 4 * y));
        double A = (x + D) / 2 , B = (x - D) / 2;
        //  printf("%f %f\n" , A , B);
        a[i] = A , b[i] = B;
        // a + b , ab
    }
    for (int i = 1 ; i <= n ; ++ i) {
        printf("%.10f%c" , a[i] - a[i - 1] , " \n"[i == n]);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        printf("%.10f%c" , b[i] - b[i - 1] , " \n"[i == n]);
    }
}