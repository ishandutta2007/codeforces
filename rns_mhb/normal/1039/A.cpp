#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1ll << 62;

#define N 200010

ll t, a[N], b[N], mn[N];
int n, x[N], y[N], c[N];

int main() {
    scanf("%d%I64d", &n, &t);
    for(int i = 1; i <= n; i ++) scanf("%I64d", &a[i]);
    a[n+1] = INF;
    for(int i = 1; i <= n; i ++) scanf("%d", &x[i]);
    for(int i = 1; i <= n; i ++) mn[i] = a[i+1] + t;
    for(int i = 1; i <= n; i ++) mn[x[i]] = a[x[i]] + t;
    b[1] = mn[1];
    for(int i = 2; i <= n; i ++) b[i] = max(b[i-1]+1, mn[i]);
    for(int i = 1; i <= n; i ++) if(b[i] < a[i+1] + t) c[i] = 1;
    y[n] = n;
    for(int i = n-1; i; i --) {
        y[i] = y[i+1];
        if(c[i]) y[i] = i;
    }
    for(int i = 1; i <= n; i ++) if(x[i] != y[i]) {
        puts("No");
        return 0;
    }
    puts("Yes");
    for(int i = 1; i <= n; i ++) printf("%I64d ", b[i]);
    puts("");
}