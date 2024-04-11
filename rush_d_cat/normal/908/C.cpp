#include <iostream>
#include <cmath>
using namespace std;
int n, r;
int x[1002];
double h[1002];

double getH(int i, int j) {
    // i > j;
    if (abs(x[i]-x[j]) > 2*r) return r;

    double dx = abs(x[i]-x[j]);
    double L = 2*r;
    double dh = sqrt(L*L - dx*dx);
    //printf("i=%d, j=%d, dh=%.5f\n", i,j,dh);
    return h[j] + dh;
}
int main() {    
    scanf("%d %d", &n, &r);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &x[i]);

    h[1] = r;
    for (int i = 2; i <= n; i ++) {
        double mx = 0;
        for (int j = 1; j < i; j ++) {
            mx = max(mx, getH(i, j));
        }
        h[i] = mx;
    }

    for (int i = 1; i <= n; i ++) {
        printf("%.9f ", h[i]);
    }

}