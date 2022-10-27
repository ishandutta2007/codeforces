#include <iostream>
#include <cmath>
using namespace std;
int n;
double x[2502], y[2502], d[2502];
double dp[2502][2502], rdp[2502][2502];

double dis(int i, int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

int main() {

    scanf("%d", &n);

    for(int i = 0; i < n; i ++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    for(int i = 0; i < n; i ++) {
        d[i] = dis(i, (i+1) % n);
    }

    for(int i = 0; i < n; i ++) {
        dp[i][1] = d[i];
        rdp[i][1]= d[(i-1+n)%n];
    }

    double ans = 0;
    for(int i = 2; i < n; i ++) {

        for(int j = 0; j < n; j ++) {
            dp[j][i] = d[j] + dp[(j+1)%n][i-1]; 
            dp[j][i] = max(dp[j][i], dis(j, (j+i)%n) + rdp[(i+j)%n][i-1]);
        }

        for(int j = 0; j < n; j ++) {
            rdp[j][i] = d[(j-1+n)%n] + rdp[(j-1+n)%n][i-1];
            rdp[j][i] = max(rdp[j][i], dis(j, (j-i+n)%n) + dp[(j-i+n)%n][i-1]);
        }

    }

    for(int i = 0; i < n; i ++) {
        ans = max(ans, dp[i][n-1]);
        ans = max(ans, rdp[i][n-1]);
    }
    printf("%.12f\n", ans);

}