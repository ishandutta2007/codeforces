#include<bits/stdc++.h>
using namespace std;

#define N 1010

int x[N];
double y[N];

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &x[i]);
        y[i] = r;
        for(int j = 1; j < i; j ++) {
            int d = abs(x[i] - x[j]);
            if(d > 2*r) continue;
            y[i] = max(y[i], y[j] + sqrt(4*r*r-d*d));
        }
        printf("%.10lf ", y[i]);
    }
    return puts(""), 0;
}