//C
#include <bits/stdc++.h>
using namespace std;

#define N 1011
#define max(a, b) ((a) > (b) ? (a) : (b))

struct dat{
    double x, y, t, r;
    dat(double x = 0, double y = 0, double t = 0, double r = 0) : x(x), y(y), t(t), r(r){}
}p[N];

bool cmp(dat a, dat b) {return a.t < b.t;}

double dist(dat a, dat b) {return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}

int n;
double ans[N];

int main(){
    //freopen("c.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%lf %lf %lf %lf", &p[i].x, &p[i].y, &p[i].t, &p[i].r);
    sort(p, p + n, cmp);
    for(int i = 0; i < n; i ++){
        ans[i] = p[i].r;
        for(int j = 0; j < i; j ++){
            double rlt = ans[j];
            if(p[i].t - p[j].t >= dist(p[i], p[j])) rlt += p[i].r, ans[i] = max(ans[i], rlt);
        }
    }
    double res = 0;
    for(int i = 0; i < n; i ++) res = max(res, ans[i]);
    printf("%lf\n", res);
}