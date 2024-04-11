#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double INF = 1e9;

struct pnt {
    double x, y;
    pnt(double x = 0, double y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &b) const {return pnt(x + b.x, y + b.y);}
    pnt operator - (const pnt &b) const {return pnt(x - b.x, y - b.y);}
    pnt operator * (const double &b) const {return pnt(x * b, y * b);}
    pnt operator / (const double &b) const {return pnt(x / b, y / b);}
    double operator & (const pnt &b) const {return x * b.x + y * b.y;}
    double operator ^ (const pnt &b) const {return x * b.y - b.x * y;}
    bool operator < (const pnt &b) const {return abs(x-b.x)<eps?(abs(y-b.y)<eps?0:y<b.y):x<b.x;}
    bool operator == (const pnt &b) const {return abs(x - b.x) < eps && abs(y - b.y) < eps;}
    bool operator <= (const pnt &b) const {return (*this) < b || (*this) == b;}
    bool operator != (const pnt &b) const {return abs(x - b.x) > eps || abs(y - b.y) > eps;}
    double dist() {return sqrt(x * x + y * y);}
    pnt rot() {return pnt(-y, x);}
    void in() {scanf("%lf%lf", &x, &y);}
};

int inter_CC(pnt c1, double r1, pnt c2, double r2, pnt *rlt) {
    double d = (c1 - c2).dist();
    if(d < eps) return 0;
    if(r1 + r2 < d || r1 + d < r2 || r2 + d < r1) return 0;
    double x = (r1 * r1 - r2 * r2 + d * d) / (d * 2);
    pnt cp = (c1 * (d - x) + c2 * x) / d;
    if(r1 + r2 == d || r1 + d == r2 || r2 + d == r1) {
        rlt[0] = cp;
        return 1;
    }
    double h = sqrt(r1 * r1 - x * x);
    pnt dv = (c2 - c1).rot() * h / d;
    rlt[0] = cp - dv, rlt[1] = cp + dv;
    return 2;
}

typedef pair <pnt, int> PPI;
pnt q[2];

int solve(int n, vector <PPI> v) {
    if(n == 1) return 2;
    if(n == 2) {
        int x = inter_CC(v[0].first, v[0].second, v[1].first, v[1].second, q);
        if(x < 2) return 3;
        else return 4;
    }
    for(int i = 0; i < 3; i ++) {
        bool flag = 1;
        for(int j = 0; j < 3; j ++) if(i != j) {
            int x = inter_CC(v[i].first, v[i].second, v[j].first, v[j].second, q);
            if(x) {flag = 0; break;}
        }
        if(flag) {
            vector <PPI> w;
            for(int j = 0; j < 3; j ++) if(j != i) w.push_back(v[j]);
            return solve(2, w) + 1;
        }
    }
    vector <pnt> a;
    for(int i = 0; i < 3; i ++) for(int j = i + 1; j < 3; j ++) {
        int x = inter_CC(v[i].first, v[i].second, v[j].first, v[j].second, q);
        for(int k = 0; k < x; k ++) {
            bool flag = 1;
            for(int h = 0; h < a.size(); h ++) if(a[h] == q[k]) {flag = 0; break;}
            if(flag) a.push_back(q[k]);
        }
    }
    int e = 0;
    for(int i = 0; i < 3; i ++) for(int j = 0; j < a.size(); j ++)
        if(abs((v[i].first - a[j]).dist() - v[i].second) < eps) e ++;
    return 2 + e - a.size();
}

int main() {
    int n;
    pnt p[3];
    double r[3];
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) p[i].in(), scanf("%lf", &r[i]);
    vector <PPI> v;
    for(int i = 0; i < n; i ++) v.push_back(PPI(p[i], r[i]));
    printf("%d\n", solve(n, v));
}