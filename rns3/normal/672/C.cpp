#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> pii;
#define max(a,b) (a>b?a:b)

const int M = 300001;

int x[M], y[M];
int vis[M];

double dist(int x, int y, int z, int w) {
    return sqrt(1. * pow(x-z,2) + 1. * pow(y-w,2));
}

double disa[M], disb[M];

int main(){
    //freopen("a.in", "r", stdin);
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
    double tot = 0;
    for(int i = 1; i <= n; i ++) tot += 2. * dist(x[i], y[i], e, f);
    for(int i = 1; i <= n; i ++) {
        disa[i] = -dist(a, b, x[i], y[i]) + dist(x[i], y[i], e, f);
        disb[i] = -dist(c, d, x[i], y[i]) + dist(x[i], y[i], e, f);
    }
    double mxa = -1e18, mxb = -1e18;
    double res = -1e18;
    int ida, idb;
    for(int i = 1; i <= n; i ++) {
        if(disa[i] > mxa) ida = i, mxa = disa[i];
        if(disb[i] > mxb) idb = i, mxb = disb[i];
    }
    res = max(mxa, mxb);
    for(int i = 1; i <= n; i ++) {
        if(i != ida) {
            res = max(res, mxa + max(0, disb[i]));
        }
        if(i != idb) {
            res = max(res, mxb + max(0, disa[i]));
        }
    }
    printf("%.12lf\n", tot - res);
}