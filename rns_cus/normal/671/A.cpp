#include<bits/stdc++.h>
using namespace std;
#define N 111111
#define ep 1e-9
int id1[N], id2[N];
double P[N], Q[N];
struct pnt{
double x,y;
 pnt(double x=0,double y=0):x(x),y(y){}
 pnt operator-(pnt a){return pnt(x-a.x,y-a.y);}
 pnt operator+(pnt a){return pnt(x+a.x,y+a.y);}
 pnt operator*(double a){return pnt(x*a,y*a);}
 pnt operator/(double a){return pnt(x/a,y/a);}
double operator^(pnt a){return x*a.y-y*a.x;}
double operator&(pnt a){return x*a.x+y*a.y;}
void  input(){x=y=0, scanf("%lf %lf",&x,&y);}
void print(){printf("%lf %lf\n",x,y);}
}p[N], pp[N];
double dist(pnt a) { return sqrt(a&a); }
bool cmp1(int i, int j) {
    return P[i] > P[j];
}
bool cmp2(int i, int j) {
    return Q[i] > Q[j];
}
int main(){
    double tot = 0;
    pnt A, B, C;
    A.input();
    B.input();
    C.input();
    int cnt;
    scanf("%d", &cnt);
    int n = 0;
    for(int i = 0; i < cnt; i ++) pp[i].input();
    for(int i = 0; i < cnt; i ++) {
        if(dist(pp[i] - C) < ep) continue;
        p[n ++] = pp[i];
    }
    for(int i = 0; i < n; i ++) {
        tot += 2. * dist(p[i] - C);
        P[i] = dist(p[i] - C) - dist(p[i] - A);
        id1[i] = id2[i] = i;
        Q[i] = dist(p[i] - C) - dist(p[i] - B);
    }

    sort(id1, id1 + n, cmp1);
    sort(id2, id2 + n, cmp2);
    if(n == 1) {
        printf("%.20lf\n", tot - max(P[id1[0]] , Q[id2[0]]));
        return 0;
    }
    if(id1[0] == id2[0]) {
        double ans = max(P[id1[0]] + Q[id2[1]], Q[id2[0]] + P[id1[1]]);
        printf("%.20lf\n", min(tot - ans, tot - max(P[id1[0]] , Q[id2[0]])));
    }
    else {
        printf("%.20lf\n", min(tot - P[id1[0]] - Q[id2[0]], tot - max(P[id1[0]] , Q[id2[0]])));
    }
    return 0;
}