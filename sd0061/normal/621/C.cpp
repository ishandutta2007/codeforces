#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , p;
int l[N] , r[N];
int main() {
    scanf("%d%d" , &n , &p);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , l + i , r + i);
        -- l[i];
    }
    double res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int j = (i + 1) % n;
        int x = r[i] / p - l[i] / p;
        int y = r[j] / p - l[j] / p;
        res += 1.0 - (1.0 - 1.0 * x / (r[i] - l[i])) * (1.0 - 1.0 * y / (r[j] - l[j]));
    }
    printf("%.15f\n" , res * 2000);
    return 0;
}