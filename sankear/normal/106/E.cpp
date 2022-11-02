#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int op = 70;
const double inf = 1e4;
const double infval = 1e17;

struct tp{
    double x, y, z;
};

int n;
double ans, ax, ay, az;
tp p[200];

inline double calc3(double x, double y, double z){
    double res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, (p[i].x - x) * (p[i].x - x) + (p[i].y - y) * (p[i].y - y) + (p[i].z - z) * (p[i].z - z));
    }
    if(res < ans){
        ans = res;
        ax = x;
        ay = y;
        az = z;
    }
    return res;
}

inline double calc2(double x, double y){
    double res = infval;
    double l = -inf;
    double r = inf;
    for(int i = 0; i < op; i++){
        double m1 = l + (r - l) / 3;
        double f1 = calc3(x, y, m1);
        double m2 = r - (r - l) / 3;
        double f2 = calc3(x, y, m2);
        res = min(res, min(f1, f2));
        if(f1 < f2){
            r = m2;
        }
        else{
            l = m1;
        }
    }
    return res;
}

inline double calc1(double x){
    double res = infval;
    double l = -inf;
    double r = inf;
    for(int i = 0; i < op; i++){
        double m1 = l + (r - l) / 3;
        double f1 = calc2(x, m1);
        double m2 = r - (r - l) / 3;
        double f2 = calc2(x, m2);
        res = min(res, min(f1, f2));
        if(f1 < f2){
            r = m2;
        }
        else{
            l = m1;
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
    }
    ans = infval;
    double l = -inf;
    double r = inf;
    for(int i = 0; i < op; i++){
        double m1 = l + (r - l) / 3;
        double f1 = calc1(m1);
        double m2 = r - (r - l) / 3;
        double f2 = calc1(m2);
        if(f1 < f2){
            r = m2;
        }
        else{
            l = m1;
        }
    }
    //printf("%.18lf\n", ans);
    //printf("%.18lf\n", calc3(0.0, 0.0, 0.0));
    printf("%.18lf %.18lf %.18lf\n", ax, ay, az);
    return 0;
}