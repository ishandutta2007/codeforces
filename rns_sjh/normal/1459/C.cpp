#include<bits/stdc++.h>
using namespace std;

#define N 200010

int n, m;
long long a[N], b[N], d;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    for(int j = 1; j <= m; j ++) scanf("%lld", &b[j]);
    d = 0;
    for(int j = 2; j <= n; j ++) d = __gcd(abs(a[1] - a[j]), d);
    for(int j = 1; j <= m; j ++) {
        long long e = __gcd(d, a[1] + b[j]);
        printf("%lld%c", e, j == m ? '\n' : ' ');
    }
}