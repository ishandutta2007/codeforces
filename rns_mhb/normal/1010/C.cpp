#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 0;
    while(n --) {
        int x;
        scanf("%d", &x);
        x = __gcd(x, k);
        ans = __gcd(ans, x);
    }
    if(ans == 0) {
        puts("1\n0");
        return 0;
    }
    printf("%d\n", k / ans);
    for(int i = 0; i < k; i += ans) printf("%d ", i);
    puts("");
}