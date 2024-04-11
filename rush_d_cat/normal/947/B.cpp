#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100000 + 10; 
typedef long long LL;
int n;
LL v[N], t[N];
LL a[N], s[N], bonu[N];
LL ans[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &v[i]);
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &t[i]);
        s[i] = s[i-1] + t[i];
    }

    for (int i = 1; i <= n; i ++) {
        int pos = upper_bound(s, s+1+n, v[i]+s[i-1]) - s - 1;
        a[i] ++, a[pos+1] --;
        bonu[pos+1] += v[i]-(s[pos]-s[i-1]);
    }
    for (int i = 1; i <= n; i ++) {
        a[i] += a[i-1];
        ans[i] = a[i] * t[i] + bonu[i];
    }
    for (int i = 1; i <= n; i ++) {
        printf("%lld ", ans[i]);
    }
}