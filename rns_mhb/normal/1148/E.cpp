#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define N 300010

int a[N], b[N], id[N], x[N<<1], y[N<<1], z[N<<1];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    int n;
    scanf("%d", &n);
    ll A = 0, B = 0;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), A += a[i];
    for(int i = 1; i <= n; i ++) id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]), B += b[i];
    sort(b + 1, b + n + 1);
    if(A != B) {
        puts("NO");
        return 0;
    }
    bool flag = 0;
    int m = 0;
    for(int i = 1, j = 1; ; ) {
        while(i <= n && a[id[i]] - b[i] >= 0) i ++;
        while(j <= n && a[id[j]] - b[j] <= 0) j ++;
        if(i > n) break;
        if(i >= j) {
            flag = 1;
            break;
        }
        int d = min(a[id[j]] - b[j], b[i] - a[id[i]]);
        ++ m;
        x[m] = id[i], y[m] = id[j], z[m] = d;
        a[id[i]] += d, a[id[j]] -= d;
    }
    if(flag) {
        puts("NO");
        return 0;
    }
    puts("YES");
    printf("%d\n", m);
    for(int i = 1; i <= m; i ++) printf("%d %d %d\n", x[i], y[i], z[i]);
}