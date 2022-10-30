#include<bits/stdc++.h>
#define ep 1e-8
#define N 3333
using namespace std;
double H[N];
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
}A[N][5], AA[5];
double dist(pnt a) {
    return sqrt(a & a);
}
bool inside(pnt a, pnt b, pnt c) {
    //if pnt a is on the segment between pnt b and pnt c, return 1.
    double A=a-b&c-b;
    double B=c-b&c-b;
    double C=a-b^c-b;
    if(fabs(C)>ep) return 0;
    if(A>-ep && A<B+ep) return 1;
    return 0;
}
int intersect(pnt a, pnt b, pnt c, pnt d) {
    double s1=b-a^d-c, s2=b-c^a-c, s;
    double t1=s1, t2=c-a^d-a;
    if(fabs(s1)<ep) {
        double dd=c-b^a-b;
        if(fabs(dd)>ep) return 2;  //parallel
        if(inside(a, c, d) || inside(b, c, d) ||
           inside(c, a, b) || inside(d, a, b)) return 2;  //overlap
        return 2;      //parallel
    }
    if(s1<0) s2*=-1, t2*=-1, s1*=-1, t1*=-1;
    if(-ep<s2 && s2<s1+ep && -ep<t2 && t2<t1+ep) {
        s=s2/s1;
        //pnt res=c+((d-c)*s);
        return 1;
    }
    return 0;
}
struct dat{
    double h, r, R;
    dat(double h = 0, double r = 0, double R = 0) :h(h), r(r), R(R){}
}p[N];
void draw(int id, double h) {
    A[id][0] = pnt(-p[id].R / 2., h + p[id].h);
    A[id][1] = pnt(-p[id].r / 2., h);
    A[id][2] = pnt(p[id].r / 2., h);
}
bool ok(int id, double h) {
    AA[0] = pnt(-p[id].R / 2., h + p[id].h);
    AA[1] = pnt(-p[id].r / 2., h);
    AA[2] = pnt(p[id].r / 2., h);
    for(int i = 0; i < id; i ++) {
        if(p[i].h + H[i] < h + ep) continue;
        if(p[id].h + h < H[i] + ep) continue;
        for(int j = 0; j < 2; j ++) {
            for(int k = 0; k < 2; k ++) {
                if(intersect(A[i][j], A[i][j+1], AA[k], AA[k + 1]) == 1) return 0;
            }
        }
    }
    return 1;
}
int main(){
    int n;
    //freopen("C.in","r",stdin);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double h, r, R;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%lf%lf%lf", &h, &r, &R);
        p[i] = dat(h, r, R);
    }
    draw(0, 0);
    for(int i = 1; i < n; i ++) {
        double mmx = 0, nnx = 0;
        for(int j = 0; j < i; j ++) mmx = max(H[j], mmx);
        for(int j = 0; j < i; j ++) nnx = max(H[j] + p[j].h, nnx);
        double st = mmx, en = nnx + 100. ;
        for(int j = 0;j < 100; j ++) {
            double mid = (st + en) / 2.;
            if(ok(i, mid)) en = mid;
            else st = mid;
        }
        H[i] = en;
        draw(i, en);
    }
    double ans = 0;
    for(int i = 0; i < n; i ++) {
        ans = max(ans, H[i] + p[i].h);
    }
    printf("%.9lf\n", ans);
    return 0;
}