#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

#define N 100010

int a[N];
pii d[N];
ll sum[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i ++) scanf("%d%d", &d[i].first, &d[i].second);
    sort(d + 1, d + m + 1);
    for(int i = 1; i <= m; i ++) sum[i] = sum[i-1] + d[i].second;
    for(int i = 1; i <= n; i ++) {
        int x = lower_bound(d + 1, d + m + 1, pii(a[i]+1, 0)) - d - 1;
        printf("%I64d%c", sum[x], " \n"[i==n]);
    }
}