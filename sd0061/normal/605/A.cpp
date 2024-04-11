#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , a[N] , p[N];
int f[N];

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        p[a[i]] = i;
    }
    int res = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        f[i] = 1;
        if (a[i] && p[a[i] - 1] < i)
            f[i] = max(f[i] , f[ p[a[i] - 1] ] + 1);
        res = max(res , f[i]);
    }
    printf("%d\n" , n - res);
    
    return 0;
}