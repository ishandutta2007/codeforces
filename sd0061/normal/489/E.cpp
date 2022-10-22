#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1005;

int n , l;
int X[N] , B[N];
double f[N];
int p[N];

double check(double val) {
    int i , j;
    for (i = 1 ; i <= n ; ++ i) {
        f[i] = 1e60;
        for (j = 0 ; j < i ; ++ j) {
            double x = f[j] + sqrt(abs(X[i] - X[j] - l));
            if (x < f[i])
                f[i] = x , p[i] = j;
        }
        f[i] -= B[i] * val;
    }
    //printf("%.10f : %.10f\n" , val , f[n]);
    return f[n];
}

void print(int x) {
    if (p[x]) print(p[x]);
    printf("%d " , x);
}

void work () {
    scanf("%d%d",&n,&l);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&X[i] , &B[i]);
    }
    double top = 0 , bot = 1e10 , mid;
    while (bot - top > 1e-10) {
        mid = (top + bot) * 0.5;
        if (check(mid) >= 0)
            top = mid;
        else
            bot = mid;
    }
    check(top);
    //printf("%.10f\n" , top);
    print(n);
}

int main() {
    work();
    return 0;
}