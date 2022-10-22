#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 105;

int n;
double p[N] , w[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        p[i] = 1 - x / 100.0;
    }
    if (n == 1) {
        puts("1");
        return 0;
    }
    double delta = 1.0;
    priority_queue< pair<double , int> > Q;    
    for (int i = 0 ; i < n ; ++ i) {
        w[i] = p[i];
        delta *= 1 - w[i];            
        Q.push(make_pair( (1.0 - w[i] * p[i]) / (1.0 - w[i]) , i));
    }
    double res = n + 1 - delta;
    while (1 - delta > 1e-12) {
        int i = Q.top().second;
        delta *= Q.top().first;
        Q.pop();
        res += 1 - delta;
        w[i] *= p[i];        
        Q.push(make_pair( (1.0 - w[i] * p[i]) / (1.0 - w[i]) , i));
    }

    printf("%.15f\n" , res);
    return 0;
}