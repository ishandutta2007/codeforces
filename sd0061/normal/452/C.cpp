#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 1000005;
double p[N];
int n , m;
inline double C(int i , int j) {
    return p[i] - p[j] - p[i - j];
}

void work() {
    int i;
    scanf("%d%d",&n,&m);
    p[0] = p[1] = 0;
    for (i = 2 ; i <= n * m ; ++ i)
        p[i] = p[i - 1] + log(i);
    double res = 0;
    for (int k = 0 ; k <= n && k <= m ; ++ k) {
        double T = log(k) + log(k) + C(m , k) + C(n * m - m , n - k) - log(n) - C(m * n , n);
        res += exp(T);
    }
    printf("%.15f\n" , res);
}

int main(){
    work();
    return 0;
}