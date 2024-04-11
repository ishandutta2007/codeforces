#include<bits/stdc++.h>
using namespace std;

int t, n, k, x[110], y[110];

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i ++) scanf("%d%d", &x[i], &y[i]);
        bool ok = 0;
        for(int i = 1; i <= n && !ok; i ++) {
            int cnt = 0;
            for(int j = 1; j <= n; j ++) cnt += (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k);
            ok = (cnt == n);
        }
        if(ok) puts("1");
        else puts("-1");
    }
}