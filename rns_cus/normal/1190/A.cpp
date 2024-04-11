#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N 100100
ll n, k, p[N];
int m;

int main() {
    scanf("%I64d %d %I64d", &n, &m, &k);
    for (int i = 1; i <= m; i ++) scanf("%I64d", &p[i]);
    int rlt = 0; ll c = 1;
    for (int i = 1; i <= m; ) {
        ll x = (p[i] - c) / k; int j = i;
        while (i <= m && p[i] - c < k * (x + 1)) i ++;
        rlt ++; c += i - j;
    }
    printf("%d\n", rlt);

    return 0;
}