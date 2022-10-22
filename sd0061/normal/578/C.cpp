#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , a[N];

double cal(double x) {
    double mn = 0 , res1 = -1e60 , res2 = 1e60 ,  s = 0;
    for (int i = 0 ; i < n ; ++ i) {
        s += a[i] - x;
        res1 = max(res1 , s - mn);
        mn = min(mn , s);
    }
    mn = s = 0;
    for (int i = 0 ; i < n ; ++ i) {
        s += a[i] - x;
        res2 = min(res2 , s - mn);
        mn = max(mn , s);
    }
    return max(res1 , -res2);
}

void work() {   
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    double l = -20000 , r = 20000 , m1 , m2;
    for (int i = 0 ; i < 100 ; ++ i) {
        m1 = (l + l + r) / 3;
        m2 = (l + r + r) / 3;
        if (cal(m1) < cal(m2))
            r = m2;
        else
            l = m1;
    }
    printf("%.12f\n" , cal((l + r) / 2));
}

int main() {
    work();
    return 0;
}