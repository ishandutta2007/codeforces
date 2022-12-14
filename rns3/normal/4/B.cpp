#include <stdio.h>
#define N 32

int n, tot;
int mn[N], mx[N];
int sum1[N], sum2[N];

int main(){
    //freopen("b.in", "r", stdin);
    scanf("%d %d", &n, &tot);
    sum1[0] = sum2[0] = 0;
    for(int i=1; i<=n; i++){
        scanf("%d %d", &mn[i], &mx[i]);
        sum1[i] = sum1[i-1] + mn[i];
        sum2[i] = sum2[i-1] + mx[i];
    }
    if(tot < sum1[n] || tot > sum2[n]) {puts("NO"); return 0;}
    puts("YES");
    int rest = tot - sum1[n];
    for(int i=1; i<=n; i++){
        if(rest < mx[i] - mn[i]) printf("%d ", mn[i] + rest), rest = 0;
        else rest -= (mx[i] - mn[i]), printf("%d ", mx[i]);
    }
    puts("");
    return 0;
}