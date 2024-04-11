#include <bits/stdc++.h>

using namespace std;

#define N 100100

int n, d;
int a[N];

int main() {
    scanf("%d%d", &n, &d);
    long long ans = 0;
    for(int i = 1; i <= n; i ++) scanf("%d", a + i);
    int id = 1;
    for(int i = 1; i <= n; i ++) {
        while(id < i) {
            if(a[i] - a[id] <= d) break;
            id ++;
        }
        if(i - id > 1) {
            ans += 1LL * (i - id) * (i - id - 1) / 2;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}