#include <bits/stdc++.h>
using namespace std;

#define ep 1e-8

const double pi = acos(-1);

struct pnt{
    double x, y;
    pnt(double x = 0, double y = 0): x(x), y(y){}

    pnt operator - (pnt a) {return pnt(x-a.x, y-a.y);}
    pnt operator + (pnt a) {return pnt(x+a.x, y+a.y);}
    pnt operator * (double a) {return pnt(x*a, y*a);}
    pnt operator / (double a) {return pnt(x/a, y/a);}
    double operator ^ (pnt a) {return x*a.y-y*a.x;}
    double operator & (pnt a) {return x*a.x+y*a.y;}

    void input(){x = y = 0, scanf("%lf %lf", &x, &y);}
    void print(){printf("%lf %lf\n", x, y);}
}p[20], q[20];

double dist(pnt a) {return sqrt(a & a);}

double ang(pnt a) {return atan2(a.y, a.x);}

bool inside(pnt b, pnt c, pnt a) {
	//if pnt a is on the segment between pnt b and pnt c, return 1.
	double A = a - b & a - c;
	double B = a - b ^ a - c;
	if (fabs(B) > ep) return 0;
	return A < ep;
}

bool repair(){
    for(int i = 0; i < 3; i ++){
        if(dist(p[2 * i] - p[2 * i + 1]) < ep) return 0;
    }
    for(int i = 0; i < 6; i ++) for(int j = i / 2 * 2 + 2; j < 6; j ++) if(dist(p[i] - p[j]) < ep) {
        int ii = i / 2, jj = j / 2;
        double ang1 = ang(p[ii * 4 + 1 - i] - p[i]);
        double ang2 = ang(p[jj * 4 + 1 - j] - p[j]);
        double del = fabs(ang1 - ang2);
        if(del > pi * 2 + ep) del -= pi * 2;
        if(del > pi / 2 + ep && del < pi * 1.5 - ep) continue;
        if(del < ep) continue;
        int k = 3 - ii - jj;
        for(int i = 0; i < 6; i ++) q[i] = p[i];
        p[0] = q[i], p[1] = q[ii * 4 + 1 - i];
        p[2] = q[j], p[3] = q[jj * 4 + 1 - j];
        p[4] = q[k * 2], p[5] = q[k * 2 + 1];
        return 1;
    }

    return 0;
}

bool ok(pnt a, pnt b, pnt c){
    double r1 = dist(a - c), r2 = dist(b - c);
    if(r1 > r2 * 4 + ep || r2 > r1 * 4 + ep) return 0;
    return 1;
}

int main(){
    ///freopen("1.in", "r", stdin);
    ///freopen("1.out", "w", stdout);
    int TC;
    for(scanf("%d", &TC); TC --;){
        for(int i = 0; i < 6; i ++) p[i].input();
        if(!repair()) {puts("NO"); continue;}

        if(!inside(p[0], p[1], p[4]) && !inside(p[0], p[1], p[5])) {puts("NO"); continue;}
        if(!inside(p[2], p[3], p[4]) && !inside(p[2], p[3], p[5])) {puts("NO"); continue;}

        pnt A, B;
        if(inside(p[0], p[1], p[4])){
            if(!inside(p[2], p[3], p[5])) {puts("NO"); continue;}
            A = p[4], B = p[5];
        }
        if(inside(p[0], p[1], p[5])){
            if(!inside(p[2], p[3], p[4])) {puts("NO"); continue;}
            A = p[5], B = p[4];
        }

        if(!ok(p[0], p[1], A) || !ok(p[2], p[3], B)) {puts("NO"); continue;}
        puts("YES");
    }
    ///return 9;
}