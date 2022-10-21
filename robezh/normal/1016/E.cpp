#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;

double s,a,b;
double l[N], r[N];
double psum[N];
int n,q;
double x[N], y[N];

int main() {

    scanf("%lf%lf%lf", &s, &a, &b);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lf%lf", &l[i], &r[i]);
    scanf("%d", &q);
    for(int i = 0; i < q; i++) scanf("%lf%lf", &x[i], &y[i]);

    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + (r[i] - l[i]);

    for(int i = 0; i < q; i++){
        double cur = 0;
        double ia = a + (x[i] - a) * (s - 0) / (s - y[i]);
        double ib = b + (x[i] - b) * (s - 0) / (s - y[i]);
        int left = lower_bound(l+1, l+n+1, ia) - l;
        left --;
        if(left != 0 && ia < r[left]) cur += r[left] - ia;
        int right = lower_bound(r+1, r+n+1, ib) - r;
        if(right != n + 1) cur -= min(r[right] - ib, r[right] - l[right]);
        else right = n;
        double res = (cur + psum[right] - psum[left]) / (ib - ia) * (b - a);
        printf("%.10f\n", res);
    }

}