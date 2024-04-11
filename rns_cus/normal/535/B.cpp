#include <bits/stdc++.h>
using namespace std;

int a[100000];

int main() {
        ///freopen("2.in", "r", stdin);
        int cnt = 0;
        for(int i = 1; i <= 9; i ++) {
            for(int j = 0; j < (1<<i); j ++) {
                int ans = 0;
                for(int k = 0; k < i; k ++) {
                    ans *= 10;
                    if(j & (1<<k)) ans += 4;
                    else ans += 7;
                }
                a[cnt ++] = ans;
            }
        }
        int n;
        scanf("%d", &n);
        int res = 0;
        for(int i = 0; i < cnt; i ++) if(a[i] <= n) res ++;
        printf("%d\n", res);
}