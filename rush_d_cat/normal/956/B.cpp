#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 200000 + 10;
int n, u;
long long a[N]; 
int main() {
    scanf("%d %d", &n, &u);
    for (int i = 1; i <= n; i ++) 
        scanf("%lld", &a[i]);
    double ans = -1;
    a[n+1] = 1e12 + 7;

    for (int i = 1; i <= n-2; i ++) {
        int pos = upper_bound(a+1, a+2+n, a[i]+u) - a - 1;
        if (pos <= i+1) continue;
        double tmp = 1.0 * (a[pos]-a[i+1]) / (a[pos]-a[i]);
        ans = max(tmp, ans);
    }
    
    if (ans < 0) {
        printf("-1\n");
    } else {
        printf("%.12f\n", ans);
    }
}