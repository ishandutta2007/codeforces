#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
const double EPS = 1e-13;

struct Bu { double x, v; int id; } bu[N];
bool cmp(Bu A, Bu B) { 
    return fabs(A.x * B.v) < fabs(B.x * A.v);
}
bool eq(Bu A, Bu B) {
    //printf("! %.5f\n", fabs(A.x * B.v) - fabs(B.x * A.v));
    return fabs(fabs(A.x * B.v) - fabs(B.x * A.v)) < 1e-6; 
}
double t1[N], t2[N], w;
int rk1[N], rk2[N];
int n, x[N], v[N];
int b[N], bit[N];
int sum(int x) {
    int ret = 0;
    while (x) {
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}
void upd(int pos, int x) {
    while (pos <= n) {
        bit[pos] += x;
        pos += pos & (-pos);
    }
}
LL DoubleSwordCombined() {
    LL ret = 0;
    for (int i = 1; i <= n; i ++) {
        b[i] = rk2[rk1[i]];
    }
    for (int i = 1; i <= n; i ++) {
        ret += (i-1) - sum(b[i]-1);
        upd(b[i], 1);
    }
    return ret;
}
int main() {
    scanf("%d %lf", &n, &w); w += 1e-6;
    for (int i = 1; i <= n; i ++) {
        scanf("%lf %lf", &bu[i].x, &bu[i].v);
        bu[i].id = i;
    }

    for (int i = 1; i <= n; i ++) {   
        bu[i].v += w;
    }
    sort(bu+1, bu+1+n, cmp);

    for (int i = 1; i <= n; i ++) {
        rk1[i] = bu[i].id; // rank -> id
    }
    for (int i = 1; i <= n; i ++) {
        bu[i].v -= 2*w;
    }
    sort(bu+1, bu+1+n, cmp);

    int las = 1; 
    for (int i = 1; i <= n; i ++) {
        if (i == 1 || !eq(bu[i-1], bu[i]))
            las = i;

        rk2[bu[i].id] = las; // id -> rank
    }
    LL ans = DoubleSwordCombined();
    printf("%lld\n", ans);
}